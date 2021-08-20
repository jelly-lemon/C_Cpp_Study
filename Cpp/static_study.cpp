/**
 * 静态成员变量初始化
 *
 * 静态常量数据成员可以在类内初始化(即类内声明的同时初始化)，也可以在类外，即类的实现文件中初始化，
 * 但不能在构造函数中初始化，也不能在构造函数的初始化列表中初始化；
 *
 静态非常量数据成员只能在类外，即类的实现文件中初始化，也不能在构造函数中初始化，不能在构造函数的初始化列表中初始化；
 *
 非静态的常量数据成员不能在类内初始化，也不能在构造函数中初始化，而只能且必须在构造函数的初始化列表中初始化；
 *
 * 非静态的非常量数据成员不能在类内初始化，可以在构造函数中初始化，也可以在构造函数的初始化列表中初始化；
 */
#include <string>
#include <iostream>
using namespace std;

class A {
public:
    static const int count = 0; // 静态常量成员可以在类内初始化
    static string rootDir;
    static void setRootDir(string dir);
};

void A::setRootDir(string dir) {
    rootDir = dir;
}

string A::rootDir; // 类的静态成员变量必须在类外分配内存空间，而且前面要加类型

/**
 普通 static 函数：
 不属于类成员函数的静态函数是一个普通的全局的静态函数。

 普通函数的定义和声明默认情况下是extern的，但静态函数只是在声明他的文件当中可见，
 不能被其他文件所用。因此定义静态函数有以下好处：
    - 其他文件中可以定义相同名字的函数，不会发生冲突。
    - 静态函数不能被其他文件所用。
 */
static void sayHello() {
    cout << "hello" << endl;
}


int main() {

    return 0;
}