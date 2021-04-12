/**
 * https 服务端
 *
 * -- 第（1）种写法 -------------------------
 * 主要使用库函数：BIO_new_ssl + BIO_new_accept +
 * BIO_do_accept + BIO_set_accept_bios + BIO_read + BIO_puts
 *
 * -- 程序功能 ------------------------------
 * 实现一个简单的 https 服务端，在浏览器输入 https://127.0.0.1，
 * 得到一个 hello world 响应。
 *
 * -- 学习目标 ------------------------------
 * 服务端证书、私钥的加载；
 * 监听的创建；
 * 判断 SSL 是否握手成功；
 * 数据的读取与响应；
 * 连接的关闭。
 *
 * -- 本文件使用方法 ------------------------
 * 直接运行
 *
 * -- 注意事项 ------------------------------
 *
 *
 */

#include <stdio.h>
#include <string.h>

#include "winsock2.h"
#include "openssl/ssl.h"
#include "openssl/bio.h"
#include "openssl/err.h"
#include "applink.c"

#define CERTF   "..\\cert\\server.crt" // 服务端的证书
#define KEYF   "..\\cert\\server.key"  // 服务端的私钥

/* 函数声明 */
void showServerInfo(BIO *abio);
void showClientInfo(BIO *abio);


void showClientInfo(BIO *abio) {
    const char *host = BIO_get_peer_name(abio);
    const char *port = BIO_get_peer_port(abio);
    printf("%s:%s connected\n", host, port);
}

void showServerInfo(BIO *abio) {
    char host_name[128];
    struct hostent *myhost = NULL;
    int i;

    printf("server info:\n");
    if (gethostname(host_name, sizeof(host_name)) < 0) {
        fprintf(stderr, "Error gethostname\n");
        exit(-2);
    }
    printf("%16s:%s\n", "host_name", host_name);
    if (!(myhost = gethostbyname(host_name))) {
        fprintf(stderr, "Error gethostbyname\n");
        exit(-3);
    }
    for (i = 0; myhost->h_addr_list[i]; i++) {
        printf("%16s:%s\n", "ip", inet_ntoa(*(struct in_addr *) myhost->h_addr_list[i]));
    }

    const char *name = BIO_get_accept_name(abio);
    const char *port = BIO_get_accept_port(abio);
    printf("accept:\n");
    printf("%16s:%s\n", "ip", name);
    printf("%16s:%s\n", "port", port);
}

int main() {
    BIO *ssl_bio, *cbio, *abio;
    SSL_CTX *ssl_ctx;
    SSL *ssl;


    // ++++++++++++++++++++++++
    // https 通信，主要是多了这些代码
    // # 加载加密套件
    SSL_library_init();

    // # 创建 ctx 对象，并加载相关证书到该对象中
    ssl_ctx = SSL_CTX_new(TLS_server_method());
    if (ssl_ctx == NULL) {
        fprintf(stderr, "SSL_CTX_new failed\n");
        ERR_print_errors_fp(stderr);
        exit(-1);
    }
    // 加载服务端的证书
    if (SSL_CTX_use_certificate_file(ssl_ctx, CERTF, SSL_FILETYPE_PEM) <= 0) {
        fprintf(stderr, "load cert failed\n");
        ERR_print_errors_fp(stderr);
        exit(-3);
    }
    // 设置打开私钥的密码
    SSL_CTX_set_default_passwd_cb_userdata(ssl_ctx, (void *)"123456");
    // 加载服务端密钥
    if (SSL_CTX_use_PrivateKey_file(ssl_ctx, KEYF, SSL_FILETYPE_PEM) <= 0) {
        fprintf(stderr, "load key failed\n");
        ERR_print_errors_fp(stderr);
        exit(-4);
    }
    // 检查证书密钥是否匹配
    if (!SSL_CTX_check_private_key(ssl_ctx)) {
        fprintf(stderr, "Private key does not match the certificate public key\n");
        ERR_print_errors_fp(stderr);
        exit(-5);
    }

    // # 创建 SSL BIO
    ssl_bio = BIO_new_ssl(ssl_ctx, 0);

    // # 获取 SSL，并进行相关设置
    BIO_get_ssl(ssl_bio, &ssl);
    if (ssl == NULL) {
        fprintf(stderr, "Can't locate SSL pointer\n");
        ERR_print_errors_fp(stderr);
        exit(-6);
    }
    // --------------------------------


    // # 创建 accept BIO 并进行相关设置
    abio = BIO_new_accept("192.168.0.108:443");
    BIO_set_accept_bios(abio, ssl_bio); // 当接收到传入连接时，这个 ssl_bio 链将被复制和预置到 abio 链中


    // # 首次调用 BIO_do_accept，创建套接字并监听
    if (BIO_do_accept(abio) <= 0) {
        fprintf(stderr, "Error setting up accept BIO\n");
        ERR_print_errors_fp(stderr);
        exit(-7);
    } else {
        showServerInfo(abio);
    }

    // # 等待连接
    while(1) {
        printf("++++++++++++++++++++++++++++++++\n");
        printf("waiting for connection...\n");

        // 后面调用 BIO_do_accept 表示等待连接(阻塞)
        if (BIO_do_accept(abio) <= 0) {
            fprintf(stderr, "Error accepting connection\n");
            ERR_print_errors_fp(stderr);
            exit(-8);
        } else {
            showClientInfo(abio);
        }

        // # 获取 connection BIO
        cbio = BIO_pop(abio);

        // # 收取消息
        printf("recv:\n");
        int count = 0;
        while (1) {
            count++;
            char data[1024];
            memset(data, '\0', 1024);
            int len = BIO_read(cbio, data, 1024);
            if (len > 0) {
                // 判断有没有读取到数据末尾，浏览器数据结束标志是 "\r\n\r\n"
                char *end = &data[len - 4];
                if (strcmp("\r\n\r\n", end) == 0) {
                    printf("[count=%d(length=%d), client send all data, stop receiving]\n", count, len);
                    printf("%s\n", data);
                    break;
                } else {
                    printf("[count=%d(length=%d), still more data, continue receiving]\n", count, len);
                }
            } else {
                if (len == 0) {
                    printf("[count=%d(length=%d), client closed connection, stop receiving]\n", count, len);
                } else {
                    printf("[count=%d(length=%d), error, stop receiving]\n", count, len);
                }
                break;
            }
        }
        printf("\n");

        // # 发送消息
        const char *header_content =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain;charset=utf8\r\n"
                "\r\n"
                "Hello world";
        int len = BIO_puts(cbio, header_content);
        if (len > 0) {
            printf("send:\n%s\n", header_content);
        } else {
            printf("send failed(len=%d):\n%s\n", len, header_content);
        }

        // # 释放空间，关闭本次连接
        BIO_free(cbio);
        printf("free connection\n");
        printf("--------------------------------\n");
    }
}