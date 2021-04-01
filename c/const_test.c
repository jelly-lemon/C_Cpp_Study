/**
 * const char *str == char const *str
 * 不可修改指针变量指向的空间，但这个指针变量的值是可以改变的
 */

void test_1() {
    const char *s1;
    char msg[100] = "hello";
    s1 = msg;
    // s1[0] = 'a';
}

void test_2() {
    char const *s1;
    char msg[100] = "hello";
    char msg1[100] = "nihao";
    s1 = msg;
    s1 = msg1;
    s1[0] = 'a';
}


int main() {
    test_2();

    return 0;
}