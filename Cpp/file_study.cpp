#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * 一次性读取文件全部内容
 *
 * 文本读取 vs 二进制读取
 * 文本读取：\r\n -> \n
 * 二进制读取：原文件是什么样的字节，就怎样读进来
 * C++ 里面的读文件函数，都是读取字节，没有经过解码得到字符串
 * C++ 里面的 string，其实是字节串
 */
void test_1() {
    // 注意路径文件，相对路径是相对 *.exe 而言的，不是 *.cpp
    // string path(R"(D:\0-3-CLion\C_Cpp_Study\Cpp\sort.cpp)");
    string path(R"(D:/0-3-CLion/C_Cpp_Study/Cpp/sort.cpp)");    // 正斜线也可以
    ifstream file(path, ios::in);
    if (!file) {
        cout << "文件不存在" << endl;
    }

    ostringstream tmp;
    tmp << file.rdbuf();
    system("chcp 65001");   // 设置控制台 utf-8 编码
    cout << tmp.str();
}

/**
 * 文件写入
 *
 * 文本写入 vs 二进制写入：
 * 如果是文本模式写入，也就是不加 ios::binary，那么 \n 会被写入为 \r\n
 * 如果是二进制模式，也就是加了 ios::binary，原字节串是什么就写入什么，不会自动添加
 * 写入文件的字节串，就是本文件的字节串，也就是本文件编码方式对写入字符串编码得到的字节串
 */
void test_2() {
    // 注意路径文件，相对路径是相对 *.exe 而言的，不是 *.cpp
    ofstream outFile("D:\\0-3-CLion\\C_Cpp_Study\\Cpp\\test.txt", ios::out | ios::binary);
    string s("你好\n欢迎光临\r\n今天天气不错\n");
    outFile.write(&s[0], s.length());
    outFile.close();
}

int main() {
    test_1();

    return 0;
}