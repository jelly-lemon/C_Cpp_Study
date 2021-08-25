#include<iostream>

using namespace std;

class A {

};

class B {
public:
    void sayHello() {
        cout << "B hello" << endl;
    }
};

class C {
public:
    virtual void sayHello() {
        cout << "C hello" << endl;
    }
};

/**
 * sizeof 类
 *


 存在虚函数时，在类中隐藏了一个指针，该指针指向虚函数表。64 位的话指针是 8 个字节。

 没有成员函数时：
 在C++早期的编译器中，这个值为0；然而当创建这样的对象时，
它们与紧接着它们后面的对象有相同的地址。比如：
B2 b2;
int a;
那么对象b2与变量a有相同的地址，这样的话对对象b2地址的操作就会影响变量a。所以在现在大多数编译器中，该值的大小为1。
 */
void test_0() {
    cout << "sizeof(A):" << sizeof(A) << endl;
    cout << "sizeof(B):" << sizeof(B) << endl;
    cout << "sizeof(C):" << sizeof(C) << endl;
}

int main() {
    test_0();

    return 0;
}