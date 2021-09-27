/**
 * 多态
 */
#include <iostream>

using namespace std;

class A {
public:
    void test() {
        cout << "A" << endl;
    }
};

class B : public A{
public:
    void test() {
        cout << "B" << endl;
    }
};

/**
 * 用基类指针调用同名函数：会调用基类的函数，而不是子类的
 */
void test_0() {
    A *p = new B();
    p->test();
}

int main() {
    test_0();

    return 0;
}