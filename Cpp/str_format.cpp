/**
 * 字符串格式化
 */

#include <stdio.h>



/**
 * sprintf 不会管你空间够不够，不够就直接使用后面得空间
 */
void test_0() {
    char msg[5];
    sprintf(msg, "abcdefg");
    printf("%s\n", msg);
}

int main() {
    test_0();
    return 0 ;
}