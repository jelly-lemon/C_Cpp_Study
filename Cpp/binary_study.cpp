#include <iostream>

using namespace std;
/**
 * 八进制输入（十进制、十六进制），都是真数，想要表示负数，就得在前面加负数
 */
void test_0() {
    int a = 015;
    cout << a << endl;

    int b = -015;
    cout << b << endl;

    // 十六进制
    int c = 0xAF;
    cout << c << endl;
}

int main() {
    test_0();

    return 0;
}