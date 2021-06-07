/**
 * const char *str == char const *str：不可修改引用变量的值
 * char* const str: 常指针变量，不能修改指针变量的值
 */
void test_1() {
    const char *s1;
    char const *s2;
    char* const s3 = "good";    // 只能初始化
    char msg1[100] = "hello";
    char msg2[100] = "nihao";
    s1 = msg1;
    s2 = msg2;
    s3 = msg2; // 不能再次赋值
    s1[0] = 'a';    // 不允许修改指针变量指向的空间
}

/**
 * int const == const int
 * 不允许修改变量的值
 */
void test_2() {
    int const a = 3;
    const int b = 4;
    a = 5;  // 不允许修改变量的值
    b = 6;
}


int main() {
    test_1();

    return 0;
}