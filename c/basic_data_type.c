/*
 * 基本数据类型的长度
 */
#include <stdio.h>

int main() {
    printf("int=%d\n", sizeof(int));
    printf("long=%d\n", sizeof(long));
    printf("long long=%d\n", sizeof(long long));
    printf("float=%d\n", sizeof(float));
    printf("double=%d\n", sizeof(double));
    printf("unsigned long long=%d\n", sizeof(unsigned long long));

    return 0;
}