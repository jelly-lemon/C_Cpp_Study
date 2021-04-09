#include <stdio.h>
#include <windows.h>
#include <c++/bits/exception_defines.h>

/**
 * 十六进制输出
 */
void test_1() {
    // %#x 输出 十六进制时会在前面加 0x
    printf("%#x\n", 0xABC);
    printf("%x\n", 0xABC);
}

/**
 * 输出内容若没有达到缓冲区大小，是不会立即输出的，除非加 fflush(stdout)
 * 比如这里将程序挂起 1s
 * 平常我们写的 printf 能立即输出，是因为程序结束时强制刷新缓冲区
 */
void test_2() {
    printf("hello\n");
    Sleep(1000);
}

/**
 * 填充和对齐
 */
void test_3() {
    // 占 5 位，不够 0 填充
    printf("%05d\n", 12);
}

/**
 * printf 实现方式
 */


int main() {
    test_3();

    return 0;
}
