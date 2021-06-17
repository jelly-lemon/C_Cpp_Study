#include <iostream>

using namespace std;

/**
 * 宏定义 __FILE__ 和 __LINE__ 当前文件和当前
 */
#define LOG(...) {\
    fprintf(stderr, "%s:line %d:\t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

/**
 * 这种通过调用函数的方式来打印调用函数所在行是行不通的
 * __LINE__ 在文件中多少行，打印出来就是这个值，不会因为函数调用而改变，
 * 只能通过宏定义的方式
 */
void info() {
    fprintf(stderr, "%s:line %d:\t", __FILE__, __LINE__);
    fprintf(stderr, "\n");
}

/**
 * 测试宏函数
 */
void test_0(){
    // 不需要分号
    LOG("hello")
}

/**
 * cout、cerr 指针
 */
void test_1() {
    ostream *p = &cerr;
    *p << "hello" << endl;
    cerr << "hello" << endl;
}

int main() {
    test_0();

    return 0;
}