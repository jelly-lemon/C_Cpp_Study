/**
* https 服务端
*
* -- 第（2）种写法 -------------------------
* 主要使用库函数：Socket + SSL_new + SSL_accept + SSL_read + SSL_write
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

void showServerInfo();


void showServerInfo() {
    char host_name[128];
    struct hostent *myhost = NULL;
    int i;

    printf("server info:\n");
    if (gethostname(host_name, sizeof(host_name)) < 0) {
        fprintf(stderr, "Error gethostname\n");
        exit(-2);
    }
    printf("\thost_name:%s\n", host_name);
    if ((myhost = gethostbyname(host_name)) == NULL) {
        fprintf(stderr, "Error gethostbyname\n");
        exit(-3);
    } else {
        for (i = 0; myhost->h_addr_list[i]; i++) {
            printf("\tip:%s\n", inet_ntoa(*(struct in_addr *) myhost->h_addr_list[i]));
        }
    }

}


int main() {
    WSADATA wsData;
    WSAStartup(MAKEWORD(2,2), &wsData);

    SOCKET sockSrv;
    SOCKADDR_IN server_addr;
    SSL *ssl;
    SSL_CTX *ssl_ctx;

    showServerInfo();


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


    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);   // ip INADDR_ANY
    server_addr.sin_port = htons(443);

    /* Set up a TCP socket */
    sockSrv = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(sockSrv, (SOCKADDR*)&server_addr, sizeof(server_addr));
    listen(sockSrv, 5);


    while (1) {
        printf("++++++++++++++++++++++++++++++++\n");
        printf("waiting for connection...\n");

        SOCKADDR_IN client_addr;
        int addrlen;
        SOCKET client_fd;
        client_fd = accept(sockSrv, (struct sockaddr *)&client_addr, &addrlen);
        if (client_fd <= 0) {
            closesocket(client_fd);
            printf("Error accept\n");
            printf("free connection\n");
            printf("--------------------------------\n");
            continue;
        } else {
            printf("TCP success\n");
            printf("%s:%d connected\n", inet_ntoa(client_addr.sin_addr), client_addr.sin_port);

        }

        ssl = SSL_new(ssl_ctx);
        SSL_set_fd(ssl, client_fd);
        int err;
        if ((err = SSL_accept(ssl)) <= 0) {
            printf("Error SSL_accept, err=%d\n", err);
            ERR_print_errors_fp(stderr);
            printf("free connection\n");
            printf("--------------------------------\n");
            closesocket(client_fd);
            SSL_free(ssl);
            continue;
        } else {
            printf("SSL success\n");
        }


        // # 收取消息
        printf("recv:\n");
        int count = 0;
        while (1) {
            count++;
            char data[1024];
            memset(data, '\0', 1024);
            int len = SSL_read(ssl, data, 1024);
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
        const char header_content[1024] =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain;charset=utf8\r\n"
                "\r\n"
                "Hello world";
        int len = SSL_write(ssl, header_content, strlen(header_content));
        if (len > 0) {
            printf("send:\n%s\n", header_content);
        } else {
            printf("send failed(len=%d):\n%s\n", len, header_content);
        }

        // 关闭连接
        SSL_shutdown(ssl);
        SSL_free(ssl);
        closesocket(client_fd);
        printf("free connection\n");
        printf("--------------------------------\n");
        continue;
    }
}