/*
 * 宏，就记住一句话，仅仅是替换而已
 *
 * 特别是有四则运算的宏，一定要加括号
 * 比如 #define add(a, b) a+b，如果不加，有代码： 3*add(2,4) 就会变成 3*2+4，而不是 3*(2+4)
 * 每一个宏里面的变量也要加小括号
 */

#include <stdio.h>

#define divide(a, b) ((a)/(b))
#define product(a, b) ((a)*(b))
#define product2(a, b) (a*b)
// 后面加 UL 表示无符号长整型 unsigned long
#define SECONDS_PER_YEAR (60 * 60 * 24 * 365UL)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int a = 6, b = 2;
    int c;

    c = divide(a, b);
    printf("a/b=%d\n", c);

    c = product(a, b);
    printf("a*b=%d\n", c);
    c = product2(2+3, 4+5);
    printf("product2(2+3, 4+5), c=%d(not 120)\n", c);
    printf("seconds=%lu\n", SECONDS_PER_YEAR);
    printf("a=%d, b=%d, min=%d\n", a, b, MIN(a, b));


    return 0;
}