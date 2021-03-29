/**
 * 单词逆序：
 * 一个英文句子中，eg:I love China. 把它按照单词逆序，变成 China love I.（或者 China. love I ？）
 *
 * 思路一：
 * 第一次完全翻转，第二次单词翻转回去。时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 思路二：
 *
 */

#include <stdio.h>
#include <string.h>
void reverse(char *start, char *end);
void words_reverse(char *str);


/**
 * 翻转给定字符串
 *
 * @param start 字符串起始地址
 * @param end 字符串最后一个字符地址
 */
void reverse(char *start, char *end) {
    char c;
    if (start == NULL || end == NULL) {
        return;
    }
    while (start < end) {
        c = *start;
        *start = *end;
        *end = c;
        start++;
        end--;
    }
}

/**
 * 翻转字符串里面的单词
 *
 * @param str 字符串起始地址
 */
void words_reverse(char *str) {
    char *end;

    if (str == NULL) {
        return;
    }
    while(*str != '\0') {
        end = str;
        while(*end != ' ' && *end != '\0') {
            end++;
        }
        reverse(str, end-1);
        str = end + 1;
    }


}


int main() {
    char str[100];

    printf("\n-----------------------------\n");
    memset(str, '\0', sizeof(str));
    strcpy(str, "I love China.");
    printf("%s\n", str);
    reverse(str, str+strlen(str)-1);
    printf("first reverse=%s\n", str);
    words_reverse(str);
    printf("words reverse=%s\n", str);

    printf("\n-----------------------------\n");
    memset(str, '\0', sizeof(str));
    strcpy(str, "How are you");
    printf("%s\n", str);
    reverse(str, str+strlen(str)-1);
    printf("first reverse=%s\n", str);
    words_reverse(str);
    printf("words reverse=%s\n", str);

    printf("\n-----------------------------\n");
    memset(str, '\0', sizeof(str));
    strcpy(str, "English");
    printf("%s\n", str);
    reverse(str, str+strlen(str)-1);
    printf("first reverse=%s\n", str);
    words_reverse(str);
    printf("words reverse=%s\n", str);

    printf("\n-----------------------------\n");
    memset(str, '\0', sizeof(str));
    strcpy(str, "English?");
    printf("%s\n", str);
    reverse(str, str+strlen(str)-1);
    printf("first reverse=%s\n", str);
    words_reverse(str);
    printf("words reverse=%s\n", str);

    return 0;
}