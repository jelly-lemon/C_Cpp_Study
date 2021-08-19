/**
* 单例模式
*/
#include <iostream>
#include <mutex>

using namespace std;

class Student{
private:
    static A* p;
    static mutex mtx;
    Student() {
        cout << "A" << endl;
    };

public:
    /*
     * 懒汉模式：第一次用时就创建
     */
    static A& getA() {
        if (p == NULL) {
            lock_guard<mutex> lockGuard(mtx);
            p = new A();
        }

        if (p == NULL) {
            throw exception();
        } else {
            return *p;
        }
    }
};

A* A::p = NULL;
mutex A::mtx;


class B {
private:
    static B *p;

    B() {
        cout << "B" << endl;
    };

public:
    /**
     * 饿汉式是在类加载的时候创建实例,所以线程是安全的.
     */
    static B& getB() {
        return *p;
    }
};
B* B::p = new B();

void test_0() {

}


int main() {
    A &a1 = A::getA();
    A &a2 = A::getA();

    B &b1 = B::getB();

    return 0;
}