#include <stdio.h>


void test_1() {
    // %#x 输出 十六进制时会在前面加 0x
    printf("%#x\n", 0xABC);
    printf("%x\n", 0xABC);
}

int main() {
    test_1();

    return 0;
}
