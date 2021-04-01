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

int main() {
    test_1();
    return 0;
}