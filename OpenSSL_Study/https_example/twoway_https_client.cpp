/**
 * 本程序是客户端，模拟浏览器访问 nginx https 双向认证服务端（自己搭建的）
 *
 * 双向认证成功，那么客户端应该收到 HTTP/1.1 200 OK（以及其它）
 */

#include <stdio.h>
#include <string.h>

#include "openssl/ssl.h"
#include "openssl/bio.h"
#include "openssl/err.h"
#include "../../include/applink.c"

#define CLIENTCERT  "..\\cert\\client_1.crt"     // 客户端的证书(需经CA签名)
#define CLIENTKEY  "..\\cert\\client_1.key"       // 客户端的私钥
#define CAFILE "..\\cert\\root.crt"              // CA 的证书


int main() {
    SSL_CTX *ssl_ctx;
    SSL *ssl;
    BIO *ssl_conn_bio;
    int len;
    char tmpbuf[1024];

    // # 加载的相关加密套件
    SSL_library_init();

    // # 创建 SSL_CTX 对象，并进行相关配置
    ssl_ctx = SSL_CTX_new(TLS_client_method());
    if (ssl_ctx == nullptr) {
        fprintf(stderr, "create SSL_CTX failed\n");
        ERR_print_errors_fp(stderr);
        exit(-1);
    }
    //SSL_CTX_set_verify(ssl_ctx, SSL_VERIFY_PEER, NULL);
    //  加载信任根证书
    if (SSL_CTX_load_verify_locations(ssl_ctx, CAFILE, NULL)<=0){
        ERR_print_errors_fp(stdout);
        exit(1);
    }
    // 加载客户端证书
    if (SSL_CTX_use_certificate_file(ssl_ctx, CLIENTCERT, SSL_FILETYPE_PEM) <= 0) {
        fprintf(stderr, "load client cert failed\n");
        ERR_print_errors_fp(stderr);
        exit(-2);
    }
    // 加载客户端密钥
    if (SSL_CTX_use_PrivateKey_file(ssl_ctx, CLIENTKEY, SSL_FILETYPE_PEM) <= 0) {
        fprintf(stderr, "load client key failed\n");
        ERR_print_errors_fp(stderr);
        exit(-3);
    }

    // # 创建 conn bio，并进行相关配置
    ssl_conn_bio = BIO_new_ssl_connect(ssl_ctx);
    BIO_set_conn_hostname(ssl_conn_bio, "www.server.com:1111");

    // # 获取 SSL 对象，并对 SSL 进行相关配置
    BIO_get_ssl(ssl_conn_bio, &ssl);
    if (ssl == nullptr) {
        fprintf(stderr, "Can't locate SSL pointer\n");
        ERR_print_errors_fp(stderr);
        exit(-4);
    }

    // # 客户端主动连接服务端
    if (BIO_do_connect(ssl_conn_bio) <= 0) {
        fprintf(stderr, "Error connecting to server\n");
        ERR_print_errors_fp(stderr);
        exit(-5);
    } else {
        printf("connection established\n");
    }

    // # 对服务端证书进行验证
//    if(SSL_get_verify_result(ssl) == X509_V_OK){
//        printf("verify ok\n");
//    } else {
//        printf("verify failed\n");
//    }

    // # 向服务端发送信息（模拟 http 请求）
    const char *head = "GET / HTTP/1.1\r\n"
                       "\r\n";

    BIO_puts(ssl_conn_bio, head);

    // # 读取服务端消息
    int count = 0;
    for (;;) {
        count++;
        printf("count=%d\n", count);
        memset(tmpbuf, '\0', 1024);
        len = BIO_read(ssl_conn_bio, tmpbuf, 1024);
        if (len <= 0) {
            printf("len=%d\n", len);
            break;
        } else {
            printf("len=%d\n", len);
        }
        printf("server response:\n");
        printf("----------------\n");
        printf("%s\n", tmpbuf);
        printf("----------------\n");
    }

    // # 释放空间
    BIO_free_all(ssl_conn_bio);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    return 0;
}