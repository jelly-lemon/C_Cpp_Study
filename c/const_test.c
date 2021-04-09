/**
 * const char *str == char const *str
 * 不可修改指针变量指向的空间，但这个指针变量的值是可以改变的
 */
void test_1() {
    char const *s1;
    char msg[100] = "hello";
    char msg1[100] = "nihao";
    s1 = msg;
    s1 = msg1;
    s1[0] = 'a';    // 不允许修改指针变量指向的空间
}

/**
 * int const == const int
 */
void test_2() {
    int const a = 3;
    const int b = 4;
    a = 5;  // 不运行修改变量的值
    b = 6;
}


int main() {
    test_2();

    return 0;
}