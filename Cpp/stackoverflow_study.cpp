#include <iostream>

using namespace std;

/**
 * 进程栈空间默认 1 Mb（比 1Mb 多点点不会出问题，不清楚实际可用是多少），超过这个大小就会报错：
 * 0xC00000FD
 */
void test_0() {
    char arr[1024*1024*2];
}

/**
 * malloc 最大可分配空间？
 *
 * 运行了一盘，分配了 1570MB，x64 环境下
 */
void test_1() {
    int count = 0;
    // 每次循环分配 1G 内存
    while(malloc(1024*1024*8)) {
        count++;
    }
    cout << count << " MB" << endl;
}

int main() {
    test_1();

    return 0;
}