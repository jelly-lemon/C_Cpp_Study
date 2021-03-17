/*
 * 重写 == 覆盖
 *
 * 收获：
 * 如果子类重写了虚函数，用父类指针指向一个子类时，调用重写函数，会执行子类的函数，而不是父类的函数。
 * 如果没有在父类函数中标记 virtual，那么父类指针调用重写函数时，执行父类函数。
 * 即使父类函数没有标记 virtual，子类有可以重写父类函数，只是不能实现多态。
 */
#include <stdio.h>

class A {

public:
    void func_1() {
        printf("A func_1\n");
    }

    virtual void func_2() {
        printf("A func_2\n");
    }
};

class B: public A {
public:
    void func_1() {
        printf("B func_1\n");
    }

    void func_2() override {
        printf("B func_2\n");
    }
};

int main() {
    B b;
    A *a = &b;
    b.func_1();
    a->func_1();
    a->func_2();

    return 0;
}