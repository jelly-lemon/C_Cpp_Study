/*
 * 重写 == 覆盖
 *
 * 收获：
 * 如果子类重写了虚函数，用父类指针指向一个子类时，调用重写函数，会执行子类的函数，而不是父类的函数。
 * 如果没有在父类函数中标记 virtual，那么父类指针调用重写函数时，执行父类函数。
 * 即使父类函数没有标记 virtual，子类也可以重写父类函数，只是不能实现多态。
 */
#include <cstdio>

class Student {

public:
    void func_1() {
        printf("A func_1\n");
    }

    virtual void func_2() {
        printf("A func_2\n");
    }

    void func_3() {
        printf("A func_3\n");
        func_2();
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

/**
 * 用基类指针调用子类函数
 * 如果基类没有标注 virtual，那么基类指针调用的函数就基类的
 * 标注了 virtual，就是调用子类的
 */
void test_0() {
    B b;
    A *a = &b;
    b.func_1();
    a->func_1();
    a->func_2();
}

/**
 * 用子类对象调用继承的函数，函数里又调用了虚函数
 * 那么执行的虚函数是子类的函数
 */
void test_1() {
    B b;
    b.func_3();
}

int main() {
    test_0();

    return 0;
}