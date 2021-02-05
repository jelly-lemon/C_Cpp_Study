/**
 * 字节对齐
 *
 * 【解析】
 * 原本以为会输出 5，结果输出 8
 * char gender 占 1 个字节，int age 占 4 个字节，int n 占 4 个字节，
 * 总共 9 个字节，
 * 但为了对齐，该结构体总共占 12 个字节（按 4 对齐）
 */

#include <stdio.h>

struct Input {
    char gender;
    int age;
};

int main(void) {
    printf("%lld\n", sizeof(struct Input));

    return 0;
}