
#include <iostream>

using namespace std;

/**
 * lambda 表达式
 *
 * [其它变量] (操作符重载函数参数) mutable 或 exception 声明 -> 返回值类型 {函数体}
 */
void test_0() {
    int n = 3;
    auto lambdaFunc = [n](const string &s) {
        for (int i = 0; i < n; i++) {
            cout << s << endl;
        }
    };

    lambdaFunc("hello");
}



int main() {
    test_0();

    return 0;
}