/*
 * int 整型变量溢出
 */
#include <iostream>
using namespace std;

/**
 * 十六进制表示与符号
 */
void test_0() {
    // 用十六进制表示的数，编译当作 unsigned int 处理
    int a1 = -0x00000001;
    cout << "a1:" << a1 << endl;
    int a2 = 0x00000001;
    cout << "a2:" << a2 << endl;

    // unsigned int 转 int：按位拷贝
    unsigned int a3 = 0x80000001;
    cout << "a3:" << a3 << " int:" << (int)a3 << endl;
    printf("%#x\n", (int)a3);
    unsigned int a4 = 0xF0000000;
    cout << "a4:" << a4 << " int:" << (int)a4 << endl;
    printf("%#x\n", (int)a4);

    // 在 unsigned int 前面添加负号转换逻辑：先按位拷贝至 int，再对 int 类型添加负号
    int a5 = -0x80000001;
    cout << "a5:" << a5 << endl;
    printf("%#x\n", (int)a5);
}

/**
 * int 最大值与最小值
 * 【易错点】负数比正数多一个，-2147483648~2147483647
 * 0x80000000 就是最小值
 */
void test_1() {
    // int 最大值
    int a1 = 0x7fffffff;
    cout << "int max:" << a1 << endl;
    // 最大值加 1 之后变最小值
    a1 += 1;
    cout << "add 1:" << a1 << endl;
    printf("%#x\n", a1);


    // int 最小值
    int a2 = 0x80000000;
    cout << "int min:" << a2 << endl;
    a2 -= 1;
    // 最小值减 1 后变最大值
    cout << "sub 1:" << a2 << endl;
    printf("%#x\n", a2);
}

int main() {
    test_1();

    return 0;
}