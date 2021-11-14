#include <string.h>
#include <stdio.h>

/**
 文件写入 \r\n

 经过测试：在 Windows 上运行，往文件写入 \n 时，
 实际上写入的是 \r\n。写入 \r 时，正常写入 \r。
 */
void test_0() {
    FILE *file;
    char *fileName = "test.txt";

    file = fopen(fileName, "w");
    char *str = "hello\r\nworld\n";
    printf("%s", str);
    fputs(str, file);
    fclose(file);
}


/**
 二进制方式写入

 二进制写入和文本写入只有一个区别：
 在 \r\n 上处理不同；
 二进制写入：内存中什么样，写入的就是什么样；
 二进制读取：文件中什么样，读取到的就什么样；
 文本读取：\r\n -> \n；\n -> \n；
 文本写入：\r\n -> \r\r\n；\n -> \r\n；
 */
void test_1() {
    FILE *pFile;
    char str[1024] = "hello\n";

    pFile = fopen("./test.txt", "wb");
    // 【重要】fwrite 写入文件：直接将内存中的内容写入文件。
    fwrite(str, sizeof(char), strlen(str), pFile);
    fclose(pFile);
}

int main() {
    test_1();

    return 0;
}