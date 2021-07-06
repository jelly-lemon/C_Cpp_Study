#include <iostream>
using namespace std;

class A {
public:
    /**
     * 仿函数必须重载 "()" 运算符，就跟写一个普通函数一样
     */
    void operator() (const string &s) const {
        cout << s << endl;
    }
};

int main() {
    A a;
    a("hello");

    return 0;
}