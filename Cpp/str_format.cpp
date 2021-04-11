/**
 * 字符串格式化
 */

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


/**
 * sprintf
 * 所以很容易出问题！
 */
void test_0() {
    char msg[10];
    int n;

    // 存在字符串数组空间溢出风险
    memset(msg, 10, '\0');
    // 不会管你空间够不够，不够就直接使用后面得空间，永远会成功
    n = sprintf(msg, "hello,%s", "world");    // 格式化后的字符串长度已经超过了字符数组，存在溢出风险
    printf("n=%d,%s\n", n, msg);

    // 安全版本
    memset(msg, 10, '\0');
    // sprintf_s()是sprintf()的安全版本，通过指定缓冲区长度来避免sprintf()存在的溢出风险
    // 字符串长度+\0 超过 目标长度时，写入失败。其余和 sprintf 一样
    n = sprintf_s(msg, 30, "hello,%s", "world");
    printf("n=%d,%s\n", n, msg);
}

/**
 * snprintf 使用
 * 和 sprintf 没有什么区别，只是多了个可以控制的字符数量
 * 没有对越界做处理
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
}

/**
 * vsnprintf 使用
 */
void test_2() {
    char msg[10];
//    vsnprintf(msg, 5, );
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


void test_6() {
    fprintf(stdout, );
}

int main() {
    test_5();
    return 0 ;
}