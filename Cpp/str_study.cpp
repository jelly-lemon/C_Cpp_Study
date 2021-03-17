/*
 * 学习 C++ 字符串的使用以及对象的创建方式
 */
#include <string>
#include <iostream>
using namespace std;


int main() {
    string s1; // string s1() 写法不能创建一个对象，空参数被当作函数声明，和 Java 不同
    cout << "s1:" << s1 << endl;

    string s2("Hello");
    cout << "s2:" << s2 << endl;

    // 重复次数
    string s3(4, 'K');
    cout << "s3:" << s3 << endl;

    // 取字串
    string s4("12345", 1, 3);
    cout << "s4:" << s4 << endl;

    string s5;  // 这是创建了一个对象吗？对，s5 就是该对象的首地址（个人理解）
    cout << "s5:" << s5 << endl;

    string s6;
    s6 = "Ni hao";
    cout << "s6:" << s6 << endl;
    cout << "s6 length= " << s6.length() << endl;

    string *s7 = new string("malloc in heap");
    cout << *s7 << endl;
    cout << "the value of pointer:" << s7 << endl;
    delete s7;


    return 0;
}