/**
 * 左值引用：引用一个左值
 * 右值引用：引用一个右值
 */

#include <iostream>
using namespace std;

/**
 * 左值引用
 */
void test_0( ) {
    int a = 10;
    int &a1 = a;    // a1 为左值引用
    cout << "a:" << a << endl;
    cout << "a1:" << a1 << endl;
    const int &a2 = a;  // 常引用，a2 也为左值引用，不过限制了引用的使用，即不运行修改
}

/**
 * 右值引用
 */
void test_1() {
    int &&a1 = 10;   // a1 为右值引用，即引用一个常量
    // 可以修改引用的对象，只要是一个常量就行
    for (int i = 0; i < 10; i++) {
        a1 = i;
        cout << a1 << " ";
    }
    cout << endl;

    const int &a2 = 10; // 常引用也可以对右值进行引用

    const int &&a3 = 10; // 常右值引用
}


int main() {

    test_1();

    return 0;
}