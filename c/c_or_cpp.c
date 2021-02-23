/**
 * 在程序中判断当前编译器是 C 编译器还是 C++ 编译器
 *
 * 如果编译器定义了 __cplusplus 宏，则说明是 C++ 编译器
 *
 * 我之前好傻，在函数外使用 printf() 函数
 */

#include <stdio.h>

int main() {
    #ifdef __cplusplus
        printf("C++\n");
    #else
        printf("C\n");
    #endif


    return 0;
}