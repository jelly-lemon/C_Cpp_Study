/*
 * socket BIO 服务端
 *
 * 程序功能：监听指定端口，accept BIO 和 connection BIO 的使用
 */

#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "openssl/bio.h"
#include "openssl/err.h"
#include "../../include/applink.c"


int main() {
    ERR_load_crypto_strings();  // 载入所有 libcrypto 函数的错误字符串

    BIO *abio, *cbio;
    char str[1024];

    // # 创建 accept BIO
    // 必须要带 IP 地址。（"4444", ":4444", "*:4444"） 都尝试过，客户端无法连接
    abio = BIO_new_accept("127.0.0.1:4444");
    // 首次调用 BIO_do_accept，检查是否创建成功
    if (BIO_do_accept(abio) <= 0) {
        fprintf(stderr, "Error setting up accept\n");
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // # 等待连接
    // 后面调用 BIO_do_accept 表示等待连接(阻塞)
    if (BIO_do_accept(abio) <= 0) {
        fprintf(stderr, "Error accepting connection\n");
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // # 获取 connection BIO
    cbio = BIO_pop(abio);

    // # 读取客户端消息
    int n = BIO_read(cbio, str, 1024);
    if (n > 0) {
        printf("client said: %s\n\n", str);
    }

    // # 向客户端发送消息
    BIO_puts(cbio, "I'm server");
    Sleep(2000);
    BIO_puts(cbio, "Nice");
    Sleep(2000);

    // # 关闭 connection BIO（已经建立连接的 BIO 就无法再通信了）
    BIO_free(cbio);

    // # 关闭 accept BIO（客户端就无法连接了）
    BIO_free(abio);

    return 0;

}