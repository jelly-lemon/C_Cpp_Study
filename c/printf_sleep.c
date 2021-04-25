/**
 * 有 Sleep 函数，printf 就不会输出，即使加了 \n？
 * 经过测试，在控制台中，加了 \n 一定是会有输出的。
 * 但是在 CLion 中就没有了，可能是管道的问题。
 *
 * 解决：
 * 在 sleep 之前 fflush(stdout) 强制刷缓冲，
 * 或者在程序开始使用 setbuf(stdout, NULL) 禁用缓冲。
 */

#include <stdio.h>
#include <windows.h>

void test_0() {
    printf("hello\n");
    fflush(stdout);
    Sleep(1000);
    printf("world\n");
}

/**
 * 即使没有 Sleep，死循环也会引起输出消失的现象
 */
void test_1() {
    int i;
    printf("hello\n");
    while (1) {

    }
    printf("world\n");
}


int main() {
    test_1();

    return 0;
}