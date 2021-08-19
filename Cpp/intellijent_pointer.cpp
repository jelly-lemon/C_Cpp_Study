/**
 * 智能指针的使用
 *
 * 动态内存管理经常会出现两种问题：一种是忘记释放内存，会造成内存泄漏；
 * 一种是尚有指针引用内存的情况下就释放了它，就会产生引用非法内存的指针。
 */
#include <iostream>
#include <memory>   // 智能指针所在文件
using namespace std;

struct Student {
    int a[102400];
};

class Student{
public:
    Student(){
        cout << "Student" << endl;
    }

    ~Student() {
        cout << "~Student" << endl;
    }
};

/**
 * shared_ptr 使用
 *
 * 特点：多个 share_ptr 可指向同一个元素
 * shared_ptr 都有一个关联的计数器，通常称其为引用计数，无论何时我们拷贝一个shared_ptr，计数器都会递增。

share_ptr 维护引用计数：
强引用, 用来记录当前有多少个存活的 shared_ptr 正持有该对象. 共享的对象会在最后一个强引用离开的时候销毁.

弱引用, 用来记录当前有多少个正在观察该对象的 weak_ptr.
当最后一个弱引用离开的时候, 共享的内部信息控制块会被销毁和释放 (共享的对象也会被释放, 如果还没有释放的话).
 */
void test_0() {
    //
    // 使用 make_shared：等所有引用计数归零一并对象内存、计数器内存
    //
    shared_ptr<string> p1 = make_shared<string>("hello");
    cout << "p1.use_count():" << p1.use_count() << endl;

    shared_ptr<string> p2 = p1; // 拷贝时，计数器先递增，再拷贝
    cout << "p1.use_count():" << p1.use_count() << endl;
    cout << "p2.use_count():" << p2.use_count() << endl;

    p2 = make_shared<string>("world");  // p2 指向另外的元素了，p1 计数器减 1
    cout << "p1.use_count():" << p1.use_count() << endl;
    cout << "p2.use_count():" << p2.use_count() << endl;

    //
    // 使用 new 来创建 share_ptr：强引用计数一旦归零就释放对象内存，强弱引用计数均归零即释放计数器内存。
    //
    auto *p = new Student();
    shared_ptr<Student> sharedPtr(p);
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
 特点：将一个 weak_ptr 绑定到一个 shared_ptr 不会改变 shared_ptr 的引用计数。
 一旦最后一个指向对象的 shared_ptr 被销毁，对象就会被释放，
 即使有 weak_ptr 指向对象，对象还是会被释放。
 */
void test_2() {
    //
    // 即使 weak_ptr 指向对象，但是如果没有 shared_ptr 了，对象仍然会被销毁
    // weak_ptr 真是太弱了（滑稽）
    //
    weak_ptr<Student> weakPtr1;
    {
        // 【易错点】make_shared<Student>() 这样就是创建一个对象
        // 错误的写法：make_shared<Student>(Student())
        shared_ptr<Student> sharedPtr1 = make_shared<Student>();
        cout << "sharedPtr1.use_count():" << sharedPtr1.use_count() << endl;

        //
        // weak_ptr 不会增加引用计数
        //
        weakPtr1 = sharedPtr1;
        cout << "weakPtr1.use_count():" << weakPtr1.use_count() << endl;

        // sharedPtr1 作用域结束，对象被析构
    }
    if (weakPtr1.expired()) {
        cout << "weakPtr1 expired" << endl;
    }
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

/**
  weak_ptr 对象被销毁时，会引起管理对象的销毁吗？腾讯一面
  不会，只要还有 shared_ptr，对象就不会被销毁
 */
void test_5() {
    shared_ptr<Student> sharedPtr1 = make_shared<Student>();
    {
        weak_ptr<Student> weakPtr1 = sharedPtr1;
    }
    cout << "sharedPtr1.use_count():" << sharedPtr1.use_count() << endl;

    shared_ptr<Student> sharedPtr2(new Student());
    {
        weak_ptr<Student> weakPtr2 = sharedPtr2;
    }
    cout << "sharedPtr2.use_count():" << sharedPtr2.use_count() << endl;
}

int main() {
    test_5();

    return 0;
}