/**
 * 模拟浏览器访问 https 网站（单向认证）
 *
 * 使用 socket 模拟 http 请求（https 本质上也是 http 协议来完成的，只不过传输内容是加密的而已）
 *
 * 没有检查服务端的证书是否可信
 */

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
#include "applink.c"


int main() {
    BIO *cbio;
    int len;
    char data[1024];
    SSL_CTX *ctx;
    SSL *ssl;

    // # 加载加密套件
    SSL_library_init();

    // # 创建 SSL_CTX
    ctx = SSL_CTX_new(TLS_client_method());

    // # 创建 ssl con bio
    cbio = BIO_new_ssl_connect(ctx);
    BIO_set_conn_hostname(cbio, "127.0.0.1:1111");  // www.baidu.com:https


    // # 获取 ssl 对象
    BIO_get_ssl(cbio, &ssl);
    if (!ssl) {
        fprintf(stderr, "can't locate ssl pointer\n");
        exit(-1);
    }

    // 进行连接
    printf("connecting...\n");
    if (BIO_do_connect(cbio) <= 0) {
        fprintf(stderr, "Error connecting to server!\n");
        exit(-2);
    }

    // # 模拟 http 请求，最后一定要加一个单独的 "\r\n"
    const char *http_header =
            "GET / HTTP/1.1\r\n"
            "\r\n";
    BIO_puts(cbio, http_header);


    // # 读取服务端响应
    printf("server response:\n");
    int count = 0;
    while (1) {
        count++;
        memset(data, '\0', 1024);
        len = BIO_read(cbio, data, 1024);
        printf("count=%d(length=%d)\n", count, len);
        if (len <= 0) {
            break;
        }
        printf("%s\n", data);
    }

    // # 释放空间
    BIO_free_all(cbio);

    return 0;
}