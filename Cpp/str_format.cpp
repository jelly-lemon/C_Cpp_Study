/**
 * 字符串格式化
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdarg>

using namespace std;


/**
 * sprintf，格式化字符串，存在风险
 */
void test_0() {
    char msg[10];
    int n;

    //
    // 存在字符串数组空间溢出风险版本
    //
    memset(msg, 10, '\0');
    // 不会管你空间够不够，不够就直接使用后面得空间，永远会成功
    n = sprintf(msg, "hello,%s", "world");    // 格式化后的字符串长度已经超过了字符数组，存在溢出风险
    printf("n=%d,%s\n", n, msg);

    //
    // 安全版本
    //
    memset(msg, 10, '\0');
    // sprintf_s() 是 sprintf() 的安全版本，通过指定缓冲区长度来避免 sprintf() 存在的溢出风险
    // 字符串长度+'\0' 超过目标长度时，会写入失败。其余和 sprintf 一样
    n = sprintf_s(msg, 30, "hello,%s", "world");
    printf("n=%d,%s\n", n, msg);
}

/**
 * snprintf 使用
 * 和 sprintf 没有什么区别，只是多了个可以控制的字符数量
 */
void test_1() {
    char msg[100];
    memset(msg, 'a', 100);
    // 格式化后的字符串（自动带有\0），然后写入目标字符数组当中。
    // 返回值是格式化后的字符串长度（要记住字符串长度不含\0）
    // 如果格式化后的字符串长度超过了给的可写入长度，就会截取写入，同时返回-1。
    int n = snprintf(msg, 10, "hello,%s\n", "world");
    puts(msg);
    printf("%d\n", n);

    char msg2[11];
    int n2 = snprintf(msg2, 10, "%s", "abcdefghiadgjn");
    cout << "n2: " << n2 << endl;
}

/**
 * vsnprintf 使用
 */
void myprint(const char *format, ...) {
    va_list arg; // 可变参数栈
    va_start(arg, format); // 初始化参数列表

    char msg[10];
    int n = vsnprintf(msg, 5, format, arg);
    va_end(arg);
    cout << "n:" << n << endl;
    cout << "msg: " << msg << endl;
}


/**
 * 字符串对齐
 */
void test_3() {
    // 右对齐，以 6 位宽度，输出字符串前 4 位
    printf("%*.*s", 6, 4, "hello,world");
}

/**
 * 前 10 位字符输出
 */
void test_4() {
    // 注意有个点，如果没有点，表示宽度为10且右对齐
    printf("%.10s...\n", "hello,world,abc");

    printf("%.10s...\n", "hello");
}

/**
 * 字符数组初始化
 */
void test_5() {
    // 只要初始化了第一个字符，其余没给值的元素会被初始化为 \0
    char s[100] = {'\0'};
    puts(s);
}

/**
 * 查看 string 的 capacity
 */
void test_6() {
    string s;
    printf("s.capacity():%lld\n", s.capacity());
    s = "hello,world";
    cout << s << endl;
    printf("s.capacity():%lld\n", s.capacity());
    s = "hello,world,ababaababababab";
    cout << s << endl;
    printf("s.capacity():%lld\n", s.capacity());
}

/**
 * 自定义变参 printf
 */
void test_7() {
    myprint("fajsdkfjkaljfdasklfjla%s", "hello, worldkslfdjlikasjfklajfkljalfjasl");
}

/**
 * char 数组转 string
 */
void test_8() {
    char msg[10] = "abc...\n";
    string s(msg);
    cout << msg << endl;
}


int main() {
    test_8();
    return 0;
}