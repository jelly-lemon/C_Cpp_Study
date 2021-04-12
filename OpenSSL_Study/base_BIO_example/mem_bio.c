/**
 * mem_bio 的一个例子
 *
 * 个人理解：在内存中开启空间，然后就可以进行读写
 */
#include <stdio.h>
#include "openssl/bio.h"

/**
 * 对 BIO_s_mem 进行读写操作
 */
void test_0() {
    BIO *b = NULL;  // 只能定义成一个指针变量
    int len = 0;
    char *out = NULL;

    // BIO 表示抽象 IO 的意思
    b = BIO_new(BIO_s_mem());   // 生成一个 mem 类型的 BIO

    // 两种写入数据的方法
    // 【易错点】字符串常量带 \0，sizeof(字符串常量)得到的结果是包含了 \0 的
    len = BIO_write(b, "openssl", sizeof("openssl")-1);   // 将字符串 "openssl" 写入 bio
    len = BIO_printf(b, "%s", "zcp");   // 将字符串 "zcp" 写入 bio
    len = BIO_write(b, ",world", sizeof(",world")-1);
    len = BIO_write(b, "ok", sizeof("ok")-1);
    BIO_write(b, "", 1);

    // 读取数据
    len = BIO_ctrl_pending(b);  // 得到缓冲区中待读取大小
    out = (char *) OPENSSL_malloc(len);
    len = BIO_read(b, out, len);    // 将 bio 中的内容写入 out 缓冲区
    printf("%s\n", out);

    // 释放空间
    OPENSSL_free(out);
    BIO_free(b);
}


void test_1() {
}

int main() {
    test_0();

    return 0;
}