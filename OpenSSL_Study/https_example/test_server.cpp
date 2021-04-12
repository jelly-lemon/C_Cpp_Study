/*
 * 服务端
 */
#include <stdio.h>
#include <string.h>
#include <openssl/ssl.h>

#include "openssl/bio.h"
#include "openssl/err.h"
#include "applink.c"

#define CERTF   "..\\cert\\server-cert.pem" // 服务端的证书(需经CA签名)
#define KEYF   "..\\cert\\server-key.pem"  // 服务端的私钥(建议加密存储)
#define CAFILE "..\\cert\\ca-cert.pem" // CA 的证书


int main() {

    BIO *ssl_bio, *buffer_bio, *accept_bio, *sock_conn_bio;
    SSL_CTX *ssl_ctx;
    SSL *ssl;


    // # 注册可用的 SSL/TLS 密码和摘要(没搞懂什么叫做注册，向谁注册？)
    SSL_library_init();

    // # 创建 ctx 对象，并进行相关配置
    ssl_ctx = SSL_CTX_new(SSLv23_server_method());
    if (ssl_ctx == nullptr) {
        fprintf(stderr, "SSL_CTX_new failed\n");
        ERR_print_errors_fp(stderr);
        exit(-1);
    }
    // CA 证书
    if ((!SSL_CTX_load_verify_locations(ssl_ctx, CAFILE, NULL)) ||
        (!SSL_CTX_set_default_verify_paths(ssl_ctx))) {
        printf("load CA cert failed\n");
        ERR_print_errors_fp(stderr);
        exit(-2);
    }
    // 加载服务端的证书
    if (SSL_CTX_use_certificate_file(ssl_ctx, CERTF, SSL_FILETYPE_PEM) <= 0) {
        fprintf(stderr, "load cert failed\n");
        ERR_print_errors_fp(stderr);
        exit(-3);
    }
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
    // 设置验证方式
    SSL_CTX_set_verify(ssl_ctx, SSL_VERIFY_PEER, NULL);

    // 设置 CA 认证的客户端
    SSL_CTX_set_client_CA_list(ssl_ctx, SSL_load_client_CA_file(CAFILE));

    // # 创建 SSL BIO
    ssl_bio = BIO_new_ssl(ssl_ctx, 0);
    // 加一个缓冲 BIO
    buffer_bio = BIO_new(BIO_f_buffer());
    ssl_bio = BIO_push(buffer_bio, ssl_bio);


    // # 获取 SSL，并进行相关设置
    BIO_get_ssl(ssl_bio, &ssl);
    if (ssl == nullptr) {
        fprintf(stderr, "Can't locate SSL pointer\n");
        ERR_print_errors_fp(stderr);
        exit(-6);
    }
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);


    while (1) {
        // 开启监听
        accept_bio = BIO_new_accept("127.0.0.1:1111");
        BIO_set_accept_bios(accept_bio, ssl_bio);
        if (BIO_do_accept(accept_bio) <= 0) {
            fprintf(stderr, "Error setting up accept BIO\n");
            ERR_print_errors_fp(stderr);
            exit(-7);
        }

        // 等待连接
        if (BIO_do_accept(accept_bio) <= 0) {
            fprintf(stderr, "connection err\n");
            ERR_print_errors_fp(stderr);
            exit(-7);
        }
        printf("connected\n");

        // 获取 conn BIO
        sock_conn_bio = BIO_pop(accept_bio);

        // 关闭监听
        //BIO_free(accept_bio);

        // 进行会话
        while (1) {
            // 读取消息
            char msg[1024];
            int n = BIO_read(sock_conn_bio, msg, 1024);
            if (n > 0) {
                printf("client said: %s\n", msg);
            }

            // 关闭连接
            if (strcmp(msg, "quit") == 0) {
                BIO_free(sock_conn_bio);
                break;
            }
        }
    }
}