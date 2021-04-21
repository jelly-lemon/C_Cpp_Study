/**
 * 类成员变量初始化
 */

#include <iostream>
using namespace std;

class A {
    int a;
public:
    /**
     * 【知识点】如果构造函数没有对成员变量初始化，则成员变量的值未知
     */
    A() {
        cout << "A init" << endl;
        cout << "a=" << a << endl;
    }
};

class B {
private:
    A a;    // 会调用无参构造函数
public:
    B() {
        cout << "B init" << endl;
    }

    /**
     * 【易错点】非初始化成员变量写法，即不是在括号后面写 a(a)，而是在构造函数里进行拷贝复制，我称之为拷贝初始化
     * 未明确初始化 vs 初始化 vs 拷贝初始化
     * 只要创建了对象，基本数据类型不明确初始化，就是随机值，其它对象就会调用默认构造函数。
     */
    B(A a) {
        cout << "B(A a)" << endl;
        this->a = a;    // 调用复制构造函数
    }
};



class C {
private:
    string name;
public:
    C(string s): name(s) {

    }
};


void test_1() {
    B b;
}

void test_2() {
    A a;
    B b(a);
}

void test_3() {
    C c("hello");
}

int main() {
    test_2();
    return 0;
}