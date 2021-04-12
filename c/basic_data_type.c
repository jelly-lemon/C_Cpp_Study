/*
 * 基本数据类型的长度
 */
#include <stdio.h>

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

void test_2() {
    int a = 1;
    int b = *(int *)((void *)&a);
    printf("%d\n", b);
}

/**
 * sizeof(字符串) 实际上得到的是字符串长度 + 1，因为字符串常量包含 \0
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
    test_3();
    return 0;
}