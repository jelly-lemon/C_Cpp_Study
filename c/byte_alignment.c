/**
 * 字节对齐
 *
 * char gender 占1个字节，int age 占4个字节，int n 占4个字节，
 * 总共9个字节，
 * 但为了对齐，该结构体总共占 12 个字节（按4对齐）
 */

#include <stdio.h>

struct Input {
    char gender;
    int age;
    int n;
};

int main(void) {
    printf("%lld\n", sizeof(struct Input));

    return 0;
}