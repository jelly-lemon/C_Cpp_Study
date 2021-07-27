/**
 * 文件打开模式：
 * r：只读，文件不存在则打开失败，文件指针在开头
 * w：只写，文件不存在则创建，文件指针在开头
 * a：只追加，文件不存在则创建，文件指针在末尾
 * r+：读写，不存在则失败，文件指针在开头
 * w+：读写，不存在则创建，文件指针在开头
 * a+：读写，不存在则创建，文件指针在末尾
 *
 *
 * 文本模式：ios::in，ios::out
 * 二进制模式：ios::binary （加了 ios::binary 就是二进制模式，不加就是文本模式）
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <direct.h>
#include <windows.h>

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
    // 中文乱码
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
    //
    // 二进制写入
    // 注意路径文件，相对路径是相对 *.exe 而言的，不是 *.cpp
    //
    ofstream outFile("./test_binary.txt", ios::out | ios::binary);
    if (outFile) {
        cout << "yes" << endl;
    }
    cout << outFile.is_open() << endl;
    string s("你好\n欢迎光临\r\n今天天气不错\n");
    outFile.write(&s[0], s.length());
    outFile.close();

    //
    // 文本写入
    // 如果文件不存在， is_ipen() 返回 false，或者直接 if 判断
    //
    outFile = ofstream("./test_txt.txt");
    if (outFile) {
        cout << "yes" << endl;
    }
    cout << outFile.is_open() << endl;
    outFile.write(s.c_str(), s.length());
    outFile.close();
}

/**
 * 创建文件夹 1
 */
void test_3() {
    //
    // mkdir 只能创建单级目录
    // 若成功则返回0，否则返回-1
    // 但经过测试，创建成功返回非 0
    // / 或 \\ 都可以
    //
    int n = mkdir(".\\test");
    printf("n=%d\n");
}

/**
 * 创建文件夹 2
 *
 */
void test_4() {
    //
    // CreateDirectory 只能创建单级目录，创建成功返回非 0
    // 如果文件夹已存在、创建失败返回 0
    //
    char dir[] = "./hello/hello";
    int n = CreateDirectory(dir, NULL);
    cout << n << endl;
}

/**
 * 判断文件夹是否存在
 */
void test_5() {
    if (_access("hello", 0) == -1) {
        cout << "hello folder not exists" << endl;
    }

    //
    // 用绝对路径
    //
    if (_access("D:/0-2-CLion/C_Cpp_Study/Cpp/leetcode", 0) != -1) {
        cout << "leetcode folder exists" << endl;
    }

    //
    // 用相对路径
    //
    if (_access("./test", 0) != -1) {
        cout << "test folder exists" << endl;
    }
}

/**
 * 获取当前程序所在路径
 * 方式 1：通过 main 参数
 * 方式 2：通过 _pgmptr
 */
void test_6() {
    cout << _pgmptr << endl;
    string path(_pgmptr);
    cout << path << endl;

    int p = path.find_last_of('\\');
    string dir = path.substr(0, p+1);
    cout << dir << endl;
}


int main() {
    test_3();

    return 0;
}