/**
 * 可变个数参数
 *
 *
 下面是 <stdarg.h> 里面重要的几个宏定义如下：
 typedef char* va_list;                     // 指向当前参数的一个指针变量
 void va_start ( va_list ap, prev_param );  // 对指针变量初始化
 type va_arg ( va_list ap, type );          // 按指定类型获取参数的值，然后指针变量指向下一个参数
 void va_end ( va_list ap );                // 关闭指针变量
 */

#include <stdio.h>
#include <stdarg.h>

/**
 * 求平均值，所有参数类型相同
 */
double average(int num, ...) {
    va_list valist;
    double sum = 0.0;
    int i;

    // 为 num 个参数初始化 valist
    va_start(valist, num);

    // 访问所有赋给 valist 的参数
    for (i = 0; i < num; i++) {
        // 提取实参
        sum += va_arg(valist, int);
    }

    // 清理为 valist 保留的内存
    va_end(valist);

    return sum / num;
}

/**
 * 实现 printf 函数
 * 【难点】如何解析 format 字符串
 * 抄自网上：https://dawnarc.com/2017/04/cprintf%E5%87%BD%E6%95%B0%E6%BA%90%E7%A0%81%E5%AE%9E%E7%8E%B0/
 *
 * @return: 打印成功的字符数量
 */
void myPrint(const char *format, ...) {
    va_list arg; // 可变参数栈
    // format 不是第一个参数吗？为什么用第一个参数初始化 arg？可以看作数组地址
    va_start(arg, format); // 初始化参数列表

    while (*format) {
        char ret = *format;
        if (ret == '%') {
            switch (*++format) {
                case 'c': {
                    char ch = va_arg(arg, int);
                    putchar(ch);
                    break;
                }
                case 's': {
                    char *pc = va_arg(arg, char *);
                    while (*pc) {
                        putchar(*pc);
                        pc++;
                    }
                    break;
                }
                default:
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;
    }
    va_end(arg);
}

/**
 * 包装 printf
 */
int printf_1(const char *format, ...) {
    va_list arg;
    int done;
    const int len = 24; // 字符数组长度
    char msg[len];

    va_start(arg, format);
    // 【易错点】要用 vsnprintf，不能用 snprintf
    // 带 v 的都是使用变量 va_list 传递变参
    // 如果格式化后的字符串长度超过 10，则会被截断，并返回 -1
    // 减 4 表示给省略号和\0的位置，即:"...\0"的位置
    done = vsnprintf(msg, len-4, format, arg);
    va_end(arg);

    // 字符串过长时，用省略号表示
    if (done == -1) {
        for (int i = 1; i <= 3; i++) {
            msg[len-1-i] = '.';
        }
        msg[len-1] = '\0';
    } else {
        msg[done] = '\0';
    }
    puts(msg);
    return done;
}


/**
 * 测试求平均值
 */
void test_0() {
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));
}

/**
 * 测试包装的 printf
 */
void test_1() {
    printf_1("%s:%d", "hellofjkonbosnbknbvlnxzbndfsobnoi", 23);
}

int main() {
    test_1();

    return 0;
}