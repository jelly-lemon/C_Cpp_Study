/*
 * const char *str
 * 不可修改指针变量指向的空间，但这个指针变量的值是可以改变的
 */


int main() {
    const char *str;
    char msg[100] = "hello";

    str = msg;

    str[0] = 'a';



    return 0;
}