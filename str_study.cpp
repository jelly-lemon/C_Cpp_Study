/*
 * 学习 C++ 字符串的使用
 */
#include <string>
#include <iostream>
using namespace std;


int main() {
    // Empty parentheses interpreted as a function declaration
    // 空参数被当作函数声明？
    string s1();
    cout << "s1:" << s1 << endl;

    string s2("Hello");
    cout << "s2:" << s2 << endl;

    string s3(4, 'K');
    cout << "s3:" << s3 << endl;

    string s4("12345", 1, 3);
    cout << "s4:" << s4 << endl;

    string s5;  // 这是创建了一个对象吗？
    cout << "s5:" << s5 << endl;

    string s6;  // 这是一个对象吗？
    s6 = "Ni hao";
    cout << "s6:" << s6 << endl;
    cout << "s6 length= " << s6.length() << endl;


    return 0;
}