/**
 * 可变个数参数
 *
 *
 下面是 <stdarg.h> 里面重要的几个宏定义如下：
 typedef char* va_list; // 指向当前参数的一个指针变量
 void va_start ( va_list ap, prev_param ); // 对指针变量初始化
 type va_arg ( va_list ap, type );  // 按指定类型获取参数的值，然后指针变量指向下一个参数
 void va_end ( va_list ap );    // 关闭指针变量
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

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++) {
        sum += va_arg(valist, int);
    }

    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum / num;
}

int main() {
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));
}