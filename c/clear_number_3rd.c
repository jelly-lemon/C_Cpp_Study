/*
 * 设置一个整数的第三位（从右往左数，即百分位的位置）
 *
 * 如，12345，设置第三位为 9，那么结果为 12945
 */
#include <stdio.h>

void set_3rd(unsigned int *p, unsigned int b) {
    if (*p <= 99) {
        return;
    }
    if (b < 0 || b > 9) {
        return;
    }

    *p = (*p / 1000) * 1000 + (b * 100) + *p % 100;
}


int main() {
    unsigned int a;
    unsigned int b;

    a = 1, b = 9;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 12, b = 9;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 123, b = 9;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 1234, b = 9;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 12345, b = 9;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);


    a = 1, b = 0;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 12, b = 0;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 123, b = 0;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 1234, b = 0;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 12345, b = 0;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);

    a = 123456, b = 0;
    printf("a=%u, b=%u,", a, b);
    set_3rd(&a, b);
    printf("set, a=%u\n", a);




    return 0;
}