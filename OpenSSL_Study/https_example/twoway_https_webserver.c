/**
 * 双向认证服务端
 *
 *
 */
#include <stdio.h>
#include <string.h>

#include "windows.h"
#include "openssl/ssl.h"
#include "openssl/bio.h"
#include "openssl/err.h"
#include "openssl/x509.h"
#include "openssl/x509v3.h"
#include "openssl/pem.h"
#include "applink.c"

#define CERTF   "..\\cert\\server.crt" // 服务端的证书
#define KEYF   "..\\cert\\server.key"  // 服务端的私钥
#define CAFILE "..\\cert\\root.crt" // CA 的证书


#define DATALEN 1024
#define OK 1
#define NO_CERT 0
#define INVALID_CERT -1
#define NOT_CREDIBLE -2

#define INFO 0
#define ERR 1

void showServerInfo(BIO *abio);
void showClientInfo(BIO *abio);
int showClientCert(BIO *cbio);
int verify_callback_server(int ok, X509_STORE_CTX *ctx);

/**
 *
 * @param abio 只能是 accept bio
 */
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




int showClientCert(BIO *cbio) {
    SSL *client_ssl;
    X509 *cert;
    char *data;


    // 获取 ssl 对象
    BIO_get_ssl(cbio, &client_ssl);

    // 从 ssl 中提取证书
    cert = SSL_get_peer_certificate(client_ssl);
    printf("client cert info:\n");
    if (cert == NULL) {
        printf("\tno cert\n");

        X509_free(cert);
        return NO_CERT;
    }

    // 获取证书链验证结果
    if (SSL_get_verify_result(client_ssl) == X509_V_OK) {
        printf("\tcert is credible\n");
    } else {
        printf("\tcert is not credible\n");
    }

    // 打印证书信息
    data = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0); // 颁发者
    printf("\tissuer: \n");
    printf("\t\t%s\n", data);

    data = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);    // 持有者
    printf("\tsubject: \n");
    printf("\t\t%s\n", data);

    // 获取证书扩展信息
    int i;
    int san_names_nb = -1;
    STACK_OF(GENERAL_NAME) *san_names = NULL;

    san_names = (STACK_OF(GENERAL_NAME) *) X509_get_ext_d2i(cert, NID_subject_alt_name, NULL, NULL);
    if (san_names == NULL) {

        X509_free(cert);
        return NOT_CREDIBLE;
    } else {
        printf("\tsubject_alt_name:\n");
        san_names_nb = sk_GENERAL_NAME_num(san_names);
        for (i = 0; i < san_names_nb; i++) {
            const GENERAL_NAME *current_name = sk_GENERAL_NAME_value(san_names, i);

            // 如果是域名
            if (current_name->type == GEN_DNS) {
                data = (char *) ASN1_STRING_get0_data(current_name->d.dNSName);
                printf("\t\t%s\n", data);
            } else if (current_name->type == GEN_IPADD) {
                // 如果是 ip
                const unsigned char *ipv4_addr;

                ipv4_addr = ASN1_STRING_get0_data(current_name->d.iPAddress);
                printf("\t\t%d.%d.%d.%d\n", ipv4_addr[0], ipv4_addr[1], ipv4_addr[2], ipv4_addr[3]);
            }
        }
        sk_GENERAL_NAME_pop_free(san_names, GENERAL_NAME_free);
    }

    // 释放证书
    X509_free(cert);

    return OK;
}

/**
 * 释放连接
 *
 * @param cbio : connectoin bio
 */
void freeConn(BIO *cbio) {
    if (cbio != NULL) {
        BIO_free(cbio);
    }
    printf("free connection\n");
    printf("--------------------------------\n");
}


int verify_callback_server(int preverify_result, X509_STORE_CTX *ctx) {

    printf("preverify_result: %d\n", preverify_result);
    return preverify_result;
}



int main() {
    BIO *ssl_bio = NULL, *cbio = NULL, *abio = NULL;
    SSL_CTX *ssl_ctx;
    SSL *ssl;

    // # 加载加密套件
    SSL_library_init();

    // # 创建 ctx 对象，对其进行设置，并加载相关证书到该对象中
    ssl_ctx = SSL_CTX_new(TLS_server_method());
    if (ssl_ctx == NULL) {
        fprintf(stderr, "SSL_CTX_new failed\n");
        ERR_print_errors_fp(stderr);
        exit(-1);
    }
    SSL_CTX_set_verify(ssl_ctx, SSL_VERIFY_PEER|SSL_VERIFY_NONE, verify_callback_server);     // 设置验证模式（双向验证），服务端会请求客户端的证书
    SSL_CTX_set_session_id_context(ssl_ctx, (const unsigned char *) "server", sizeof("server")); // 设置会话 id，随便给一个字符串

    // # 加载证书到 ctx
    // CA 证书，用来验证客户端证书是否可信
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
    SSL_CTX_set_default_passwd_cb_userdata(ssl_ctx, (void *)"123456");  // 设置私钥文件解密密码
    if (SSL_CTX_use_PrivateKey_file(ssl_ctx, KEYF, SSL_FILETYPE_PEM) <= 0) {
        fprintf(stderr, "load key failed\n");
        ERR_print_errors_fp(stderr);
        exit(-4);
    }
    // # 检查证书密钥是否匹配
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

    // # 创建 accept BIO 并进行相关设置
    abio = BIO_new_accept("10.66.38.27:4433");
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



        // 后面调用 BIO_do_accept 表示等待 TCP 连接(阻塞)
        if (BIO_do_accept(abio) <= 0) {
            fprintf(stderr, "Error accepting connection\n");
            ERR_print_errors_fp(stderr);
            freeConn(cbio);
            continue;
        } else {
            showClientInfo(abio);
        }

        // # 获取 connection BIO
        cbio = BIO_pop(abio);

        // SSL 握手
        if (BIO_do_accept(cbio) <= 0) {
            fprintf(stderr, "Error SSL handshake\n");
            ERR_print_errors_fp(stderr);
            freeConn(cbio);
            continue;
        } else {
            printf("SSL handshake success\n");
        }

        // 展示证书信息
        showClientCert(cbio);

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
                "Content-Length: 11\r\n"
                "\r\n"
                "Hello world";
        int len = BIO_puts(cbio, header_content);
        if (len > 0) {
            printf("send:\n%s\n", header_content);
        } else {
            printf("send failed(len=%d):\n%s\n", len, header_content);
        }
        freeConn(cbio);
    }
}