/**
 * 学习 C++ 字符串的使用以及对象的创建方式
 */
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

/**
 * string 对象创建
 */
void test_1() {
    // 这是创建了一个对象吗？对
    string s1; // string s1() 写法不能创建一个对象，空参数被当作函数声明，和 Java 不同
    cout << "s1:" << s1 << endl;

    // 通过构建函数创建
    string s2("Hello");
    cout << "s2:" << s2 << endl;

    // 重复某个字符
    string s3(4, 'K');
    cout << "s3:" << s3 << endl;

    // 取子串。结束位置超过了原字符串长度也没关系，有多少返回多少
    string s4("12345", 1, 36);
    cout << "s4:" << s4 << endl;

    // 取字串，指定起始位置
    string s5 = string("hello").substr(2);
    cout << "s5:" << s5 << endl;

    // 取子串，给定字串长度
    // 【易错点】第二个参数表示字串长度，不是起始位置
    string s6("hello", 1);
    cout << "s6: " << s6 << endl;

    // 获取字符串长度
    string s7;
    s7 = "Ni hao";
    cout << "s7:" << s7 << endl;
    cout << "s7 length= " << s7.length() << endl;

    // 在堆中开启空间
    string *s8 = new string("malloc in heap");
    cout << *s8 << endl;
    cout << "the value of pointer:" << s8 << endl;
    delete s8;

    // 在栈中开辟空间
    char t[10] = "hello";
    string s9(t);
    cout << "s9: " << s9 << endl;
}

/**
 * string 与 char 的拼接
 */
void test_2() {
    string s1;
    char s2[] = "nihao";
    char s3[] = "hello";
    char s4[] = "\0\0";
    char *s5 = (char *) malloc(sizeof(char) * 10);

    s1 += s2;
    s1 += s3;
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.length() << endl;

    // \0 不会影响字符串的长度
    // size 与 length 没有任何区别
    s1 += s4;
    cout << s1.size() << endl;
    cout << s1.length() << endl;

    // 除了 \0，其余都会计入长度
    s1 += "\r\n";
    cout << s1.size() << endl;
    cout << s1.length() << endl;

    // 释放原数组不会影响 s1，说明是复制了过去
    memcpy(s5, "googe\0", 6);
    s1 += s5;
    free(s5);
    cout << s1 << endl;

    // 取 string 首地址
    string s6("hello");
    printf("s6=%s\n", &s6[0]);

    string s7 = "hello";
    s7 += '.';
}

/**
 * 字符串查找
 */
void test_3() {
    int n;
    string s = "hello\r\nnihao\r\n\r\n";
    // 如果找到字串，返回首字母下标
    n = s.find("\r\n\r\n");
    cout << n << endl;

    // 如果查找不到字串，返回 -1
    n = s.find("abc");
    cout << n << endl;


    n = s.find_last_of('\n');
    cout << n << endl;
}

/**
 * 字符串转数字
 */
void test_4() {
    string s(" 123");   // 即使字符串前面有空格也没关系
    // atoi == alphanumeric to integer
    int n = stoi(s);
    cout << n << endl;

    try {
        string s2("abc");
        n = stoi(s2);
        cout << n << endl;
    } catch (...) {
        // 捕获到任何异常都抛出
        throw;
    }
}

/**
 * 字符串编码
 * string, char s[10] 都是字节串
 */
void test_5() {
    // 设置控制台编码为 UTF-8，默认为 GBK
    system("chcp 65001");

    // 文件编码为 UTF-8 时，char 数字存储“你好”：\344\275\240\345\245\275
    // 文件编码为 GBK 时，char 数字存储“你好”：\304\343\272\303
    // 所以，在文件中输入的字符串，C++ 中存储的是文件编码对应的字节
    // 打印到控制台时，我猜测 C++ 应该是直接把字节串传过去了
    char s[10] = "你好";
    cout << s << endl;

    string s1("你好");
    cout << s1 << endl;
}


/**
 * 字符串替换
 */
void test_6() {
    string s = "/abc/def/a/b/c";

    //替换所有指定子串
    int pos = 0;
    while ((pos = s.find('/')) != -1) {
        s.replace(pos, 1, "\\");
    }

    cout << s << endl;
}

/**
 * 字符串长度
 */
void test_7() {
    string s = "hello";
    cout << s << "," << " length = " << s.length() << endl;
}

/**
 * 字符替换
 */
void test_8() {
    string s = "hello";
    s[0] = 'a';
    cout << s << endl;
}

/**
 * string 末尾有 \0 吗？有
 */
void test_9() {
    string s = "nihao";
    char c = s[5];
    printf("%d\n", c);
}


/**
 * 访问单个字符
 */
void test_10() {
    string s = "nihao";
    char c1 = s[0];
    cout << c1 << endl;
}

/**
 * 字符串分割
 */
void test_11() {
    string ip("127.0.0.1");

}

/**
 * 字符串查找某个字符
 */
void test_12() {
    string s("hello,world,0526");
    int p = 0;
    while (1) {
        p = s.find(',', p);
        if (p != -1) {
            cout << p << endl;
        } else {
            break;
        }
        p++;
    }
}

/**
 * 十六进制字符串转数字
 */
void test_13() {
    long n = strtol("0x000F", NULL, 16);
    if (n == 0x000F) {
        cout << n << endl;
    }
}


/**
 * 字符串比较
 */
void test_14() {
    string s1("abc");
    string s2("def");
    int n = strcmp(s1.c_str(), s2.c_str());
    cout << n << endl;
}

/**
 * 流缓存：一块自动伸缩的内存数组做缓存
 * streambuf 是基类
 * filebuf，stringbuf 又分别作为 fstream 文件流, stringstream 字符串流 底层的流缓存部分。
    用 stream.rdbuf() 返回 所在流对应的 流缓存对象。
 *
 */
void test_15() {
    stringbuf buf;
}

int main() {
    test_14();

    return 0;
}