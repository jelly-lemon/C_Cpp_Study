/**
 * 根据我的实验，返回本地对象时，并不会出现拷贝构造。难道是被优化了吗？对的
 * 同样，返回临时对象时，仍然不会出现拷贝构造。
 *
 * 【注意】编译选项加入：-fno-elide-constructors，取消编译优化
 */

#include <iostream>
#include <cstring>

using namespace std;



class Human {
private:
    char *name;
    int *pAge;

public:
    /**
     * 普通构造函数
     */
    Human(char *name, int age): pAge(new int(age)) {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        cout << "constructor:" << this->name << ", age:" << *this->pAge << endl;
    }

    /**
     * 析构函数
     */
    ~Human() {
        if (this->name != nullptr)
            cout << "desconstructor:" << this->name << " died." << endl;
        else
            cout << "desconstructor" << endl;
        delete name;
        delete pAge;
    }

    /**
     * 拷贝构造
     *
     * 【易错点】拷贝构造函数，必须添加 const
     */
    Human(const Human &h) {
        this->name = new char[strlen(h.name)+1];
        strcpy(this->name, h.name);
        this->pAge = new int(*h.pAge);
        cout << "copy constructor:" << this->name << ", age:" << *this->pAge << endl;
    }

    /**
     * 赋值运算符
     */
    Human &operator=(const Human &h) {
        if (this != &h) {
            this->name = new char[strlen(h.name)+1];
            strcpy(this->name, h.name);
            this->pAge = new int(*h.pAge);
            cout << "copy assignment:" << this->name << ", age:" << *this->pAge << endl;
        }
        return *this;
    }

    // 移动拷贝构造函数：现有对象 a，现有有对象 b，把 a 拥有的用 new 申请的空间交给 b 管理，a 置为 nullptr
    // Move constructor should be marked noexcept
    // 该关键字告诉编译器，函数中不会发生异常，这有利于编译器对程序做更多的优化。
    Human(Human &&h) noexcept:pAge(h.pAge), name(h.name) {
        h.pAge = nullptr;
        h.name = nullptr;
        cout << "move copy constructor:" << this->name << ", age:" << *this->pAge << endl;
    }
};



/**
 * 获取一个对象（本地对象方式）
 */
Human getHuman_1() {
    // 返回本地对象
    // 1.构造本地对象 h
    // 2.调用拷贝构造，将本地对象h 拷贝到外部存储器
    // 3.调用析构函数析构本地对象 h
    char name[20] = "Laomei";
    Human h(name, 18);

    return h;
}

/**
 * 获取一个对象（临时对象方式）
 *
 * 但经过我测试，不管是返回本地对象，还是返回临时对象，
 * 都会经历从本函数到外部栈拷贝构造的过程
 */
Human getHuman_2() {
    // 返回临时对象
    // 编译器直接把临时对象创建在外部存储器中（主调函数的栈帧中），
    // 省去了拷贝和析构的花费，提高了效率
    char name[20] = "nihao";
    return Human(name, 8);
}

/**
 * 各种方法创建对象
 */
void test_0() {
    char name[20] = "Six";
    Human h1(name, 6);        // 普通构造
//    Human h2 = getHuman_1();      // 拷贝构造（【易错】不是拷贝赋值），之后 getHuman_1 返回的临时对象会被立即析构
    Human h3(getHuman_2());
    Human h4(h1); // 拷贝构造
}

/**
 * A a(...) 与 A a = A(...) 等价吗？
 * 理论上不等价，但会被编译器优化为 A a(...)，变成等价的。
 * 也就是说 A a = A(...) 不会调用拷贝构造函数。
 */
void test_1() {
    char name1[20] = "sleep";
    char name2[20] = "goodman";
    Human h1(name1, 89);
    Human h2 = Human(name2, 35);
}

/**
 * 移动拷贝构造
 */
void test_2() {
    char name1[20] = "sleep";
    char name2[20] = "goodman";
    // Human(name1, 89) 是匿名变量，当作右值处理
    Human h1(Human(name1, 89));
    // move 函数将左值转换为右值
    Human h2(move(h1));
}

int main() {
    test_2();

    return 0;
}