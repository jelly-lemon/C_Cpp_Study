/**
 * 智能指针的使用
 *
 * 动态内存管理经常会出现两种问题：一种是忘记释放内存，会造成内存泄漏；
 * 一种是尚有指针引用内存的情况下就释放了它，就会产生引用非法内存的指针。
 */
#include <iostream>
#include <memory>   // 智能指针所在文件
using namespace std;

struct A {
    int a[102400];
};

/**
 * shared_ptr 使用
 *
 * 特点：多个 share_ptr 可指向同一个元素
 *
 * shared_ptr都有一个关联的计数器，通常称其为引用计数，无论何时我们拷贝一个shared_ptr，计数器都会递增。
 */
void test_0() {
    shared_ptr<string> p1 = make_shared<string>("hello");
    cout << "p1.use_count():" << p1.use_count() << endl;

    shared_ptr<string> p2 = p1; // 拷贝时，计数器先递增，在拷贝
    cout << "p1.use_count():" << p1.use_count() << endl;
    cout << "p2.use_count():" << p2.use_count() << endl;

    p2 = make_shared<string>("world");  // p2 指向另外的元素了，p1 计数器减 1
    cout << "p1.use_count():" << p1.use_count() << endl;
    cout << "p2.use_count():" << p2.use_count() << endl;
}

/**
 * unique_ptr
 *
 * 特点：独占某个元素，不支持拷贝和赋值操作
 */
void test_1() {
    unique_ptr<string> p1(new string("hello"));

    // 转移所有权
    unique_ptr<string> p2(p1.release());
}


/**
 * weak_ptr
 *
 * 特点：将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数。
 * 一旦最后一个指向对象的shared_ptr被销毁，对象就会被释放，即使有weak_ptr指向对象，对象还是会被释放。
 */
void test_2() {
    shared_ptr<string> p1 = make_shared<string>("hello");
    cout << "p1.use_count():" << p1.use_count() << endl;

    // weak_ptr 不会增加引用计数
    weak_ptr<string> p2 = p1;
    cout << "p2.use_count():" << p2.use_count() << endl;
}

/**
 * scoped_ptr
 *
 * 不是 C++11 标准里面的
 */
void test_3() {

}

/**
 * 结构体复制
 */
void test_4() {
    A a = {};
    A b = {};
    a = b;
    a = b;
    a = b;
}

int main() {
    test_4();

    return 0;
}