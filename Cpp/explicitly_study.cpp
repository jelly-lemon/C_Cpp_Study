/**
 * explicitly 使用
 *
 * 隐式转换存在风险
 * 风险再现的例子还没找到
 */
#include <iostream>
using namespace std;

class A{
    //  成员变量和函数默认是私有的
    float m;

public:
    A(float m): m(m) {

    }

    float getM() {
        return m;
    }
};


class B{
    float m;

public:
    // 该关键字只能用来修饰类内部的构造函数
    // 使用了该关键字，就不允许 B b = 3.14 了，只能用 B b(3.14)
    // 该关键字只针对只有一个参数的构造函数
    explicit B(float m): m(m) {

    }

    float getM() {
        return m;
    }
};

int main() {

    A a = 123456789;
    cout << "a.m= " << a.getM() << endl;

    B b(123456789);
    cout << "b.m= " << b.getM() << endl;

    return 0;
}