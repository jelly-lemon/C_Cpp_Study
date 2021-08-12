/**
 * move：强制转为右值
 * forward：完美转发，函数外是右值，传入函数后依旧是右值。同理左值。
 *
 * 如果一个变量或者参数被声明为 T&&，其中 T 是被推导的类型，那这个变量或者参数就是一个万能引用（universal reference）。
 */
#include <iostream>

using namespace std;

/**
 * 左值引用
 */
template<class T>
void print(T &t) {
    cout << "左值" << endl;
}

/**
 * 右值引用
 */
template<class T>
void print(T &&t) {
    cout << "右值" << endl;
}

template<class T>
void testForward(T &&v) {
    print(v);
    print(forward<T>(v));
    print(move(v));
}

void test_0() {
    // 数字 1 是右值
    testForward(1);

    cout << "===============" << endl;

    // 变量 x 是左值
    int x = 1;
    testForward(x);
}


int main() {
    system("chcp 65001");

    test_0();

    return 0;
}