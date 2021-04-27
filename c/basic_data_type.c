/**
 * 基本数据类型的长度
 */
#include <stdio.h>

/**
 * 基本数据类型所占字节长度
 * long 和 int 都占 4 个字节
 */
void test_1() {
    printf("int=%d\n", sizeof(int));
    printf("long=%d\n", sizeof(long));
    printf("long long=%d\n", sizeof(long long));
    printf("float=%d\n", sizeof(float));
    printf("double=%d\n", sizeof(double));
    printf("unsigned long long=%d\n", sizeof(unsigned long long));
    printf("void *=%d\n", sizeof(void *));
    printf("int *=%d\n", sizeof(int *));
}

/**
 * 地址类型可以随意转换
 */
void test_2() {
    int a = 1;
    int b = *(int *)((void *)&a);
    printf("%d\n", b);
}

/**
 * sizeof(字符串) 得到所占字节长度，字符串常量末尾包含 \0，所以看起来要多一个字节
 */
void test_3() {
    int n = sizeof("\r\n");
    printf("\\r\\n=%d\n", n);

    n = sizeof("\r\n\0");
    printf("\\r\\n\\0=%d\n", n);

    n = sizeof("\r");
    printf("\\r=%d\n", n);

    n = sizeof("\n");
    printf("\\n=%d\n", n);

    n = sizeof("");
    printf("\"\"=%d\n", n);

    n = sizeof("abc\r\n");
    printf("abc\\r\\n=%d\n", n);
}

int main() {
    test_1();
    return 0;
}