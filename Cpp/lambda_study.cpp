
#include <iostream>

using namespace std;

/**
 * lambda 表达式
 *
 * [函数对象参数] (操作符重载函数参数) mutable 或 exception 声明 -> 返回值类型 {函数体}
 */
void test_0() {
    auto lambdaFunc = [](string s) {
        cout << s << endl;
    };

    lambdaFunc("hello");
}



void test_1() {


}

int main() {
    test_0();

    return 0;
}