/**
 * 文件写入 \r\n
 *
 * 经过测试：在 Windows 上运行，往文件写入 \n 时，
 * 实际上写入的是 \r\n。写入 \r 时，正常写入 \r。
 */

#include <string.h>
#include <stdio.h>

int main() {

    FILE *file;
    char *fileName = "log.txt";

    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("文件不存在！\n");
        return 0;
    }

    char *str = "hello\r\nworld\n";
    printf("%s", str);
    fputs(str, file);
    fclose(file);

    return 0;
}