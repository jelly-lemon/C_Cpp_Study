/**
 * 循环引用
 */


#include <iostream>
#include <memory>

using namespace std;

class Parent;

typedef std::shared_ptr<Parent> ParentPtr;

class Child {
public:
    ParentPtr father;

    Child() {
        cout << "hello Child" << endl;
    }

    ~Child() {
        cout << "bye Child\n";
    }
};

typedef std::shared_ptr<Child> ChildPtr;

class Parent {
public:
    ChildPtr son;

    Parent() {
        cout << "hello parent\n";
    }

    ~Parent() {
        cout << "bye Parent\n";
    }
};

/**
 * 循环引用
 *
 * c只有调用p的析构的时候，才能被释放。
 * p只有调用c的析构的时候，才能被释放。
 * 形成了循环引用，造成了内存泄露。
 * 我觉得很奇怪，既然不会报错。。。
 *
 * 问题：两者相互包含，这明显是有悖常理的，设计上不合理
 */
void test_0() {
    ParentPtr p(new Parent());
    ChildPtr c(new Child());
    p->son = c;
    c->father = p;
}

int main() {
    test_0();

    return 0;
}