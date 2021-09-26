

#include <stdio.h>


void change(int **p) {
    static int n = 999;

    (*p) = &n;
}

/**
 * 改变指针变量的值
 *
 * -- 学习目标 ---------
 * 函数传递，改变指针变量的值；
 * 理解 **p 的含义；
 */
void test_0() {
    int *p1 = NULL;
    int a = 10;

    p1 = &a;

    change(&p1);

    printf("%d\n", *p1);
}

/**
 * 指针变量、字符串常量、字符数组
 */
void test_1(){
    // 字符数组
    char str1[] = "abc";
    char str2[] = "abc";

    // 字符数组
    const char str3[] = "abc";
    const char str4[] = "abc";

    // 指针变量
    const char *str5 = "abc";
    const char *str6 = "abc";

    // 指针变量
    char *str7 = "abc";
    char *str8 = "abc";

    if (str1 == str2) {
        printf("1\n");
    }
    if (str3 == str4) {
        printf("3\n");
    }
    if (str5 == str6) {
        printf("5\n");
    }
    if (str7 == str8) {
        printf("7\n");
    }

}

int main() {
    test_1();

    return 0;
}

