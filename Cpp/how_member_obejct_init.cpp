/**
 * 类成员变量被自动初始化吗？
 * 会的，会调用无参构造函数。
 * 那要是没有无参构造函数呢？
 */

#include <iostream>
using namespace std;

class A {
public:
    A();
};

A::A() {
    cout << "A init" << endl;
}

class B {
private:
    A a;    // 会调用无参构造函数
public:
    B();
};

B::B() {

    cout << "B init" << endl;
}

class C {
private:
    string name;
public:
    C(string s);
};

C::C(string s):name(s) {

}

void test_1() {
    B b;
}

void test_2() {
    C c("hello");
}

int main() {
    test_2();
    return 0;
}