#include <string.h>
#include <stdio.h>

/**
 * strcat 使用
 * strcat 会自动拼接到前一个字符串 '\0' 处
 */
void test_0() {
    char s1[20] = "hello";
    char s2[10] = ",world";
    char s3[5] = "!!";
    strcat(s1, s2);
    printf("%s\n", s1);
    strcat(s1, s3);
    printf("%s\n", s1);
}


int main() {
    test_0();
    return 0;
}