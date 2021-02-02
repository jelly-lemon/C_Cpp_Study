/**
 * 改变指针变量的值
 *
 * -- 学习目标 ---------
 * 函数传递，改变指针变量的值；
 * 理解 **p 的含义；
 */

#include <stdio.h>


void change(int **p) {
    static int n = 999;

    (*p) = &n;
}

int main() {
    int *p1 = NULL;
    int a = 10;

    p1 = &a;

    change(&p1);

    printf("%d\n", *p1);

    return 0;
}

