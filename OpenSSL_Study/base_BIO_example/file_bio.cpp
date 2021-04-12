/*
 * 文件 BIO
 */
#include <stdio.h>
#include <openssl/bio.h>

int main() {

    BIO *b = NULL;

    int len = 0, outlen = 0;

    char *out = NULL;


    b = BIO_new_file("file_bio.txt", "w");    // 创建一个文件

    len = BIO_write(b, "openssl", 7);

    len = BIO_printf(b, "%s", "zcp");   // 写入内容

    BIO_free(b);    // 释放 bio

    b = BIO_new_file("bf.txt", "r");

    len = BIO_pending(b);   // 返回 BIOs 读取和写入缓冲区中的挂起字符数(没搞懂啥意思，试了一下，返回值为0)

    len = 50;

    out = (char *) OPENSSL_malloc(len); // 开辟空间

    // 循环读取出所有字符
    len = 1;
    while (len > 0) {
        len = BIO_read(b, out + outlen, 1);
        outlen += len;
    }

    printf("%s\n", out);

    BIO_free(b);
    free(out);

    return 0;

}