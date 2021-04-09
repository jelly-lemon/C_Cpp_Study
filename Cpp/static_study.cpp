/**
 * 静态成员变量初始化
 *
 * 静态常量数据成员可以在类内初始化(即类内声明的同时初始化)，也可以在类外，即类的实现文件中初始化，
 * 但不能在构造函数中初始化，也不能在构造函数的初始化列表中初始化；
 *
 * 静态非常量数据成员只能在类外，即类的实现文件中初始化，也不能在构造函数中初始化，不能在构造函数的初始化列表中初始化；
 *
 * 非静态的常量数据成员不能在类内初始化，也不能在构造函数中初始化，而只能且必须在构造函数的初始化列表中初始化；
 *
 * 非静态的非常量数据成员不能在类内初始化，可以在构造函数中初始化，也可以在构造函数的初始化列表中初始化；
 */
#include <string>
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

int main() {

    return 0;
}