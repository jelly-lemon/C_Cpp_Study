//
// Created by lemon local on 2020/7/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 题目：
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 注意：如果输入是空串，要求返回 NULL
 */

char num[][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void getCombinations(int i, const char* digits, char ***result, int *count, char s[]);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    char **result = NULL;
    int count = 0;
    int N = strlen(digits);
    char *s = (char *)malloc(sizeof(char) * (N + 1));
    getCombinations(0, digits, &result, &count, s);


    *returnSize = count;

    return result;
}

/**
 * 获取所有组合
 * @param i 当前第 i 个数字，从 0 开始
 * @param n 输入的数字个数
 * @param result
 * @param count
 */
void getCombinations(int i, const char* digits, char ***result, int *count, char s[]) {
    const int N = strlen(digits);
    if (N == 0) {
        (*result) = NULL;
        return;
    }
    if (i >= N) {
        (*count)++;
        (*result) = (char**)realloc((*result), (*count) * sizeof(char *));
        s[N] = '\0';
        char *t = (char *)malloc(sizeof(char) * (N + 1));
        strcpy(t, s);
        (*result)[(*count) - 1] = t;
        return;
    }

    int k = digits[i] - '0';
    const int m = strlen(num[k]);
    int j;
    for (j = 0; j < m; j++) {
        s[i] = num[k][j];
        getCombinations(i + 1, digits, result, count, s);
    }

}

//int main(void) {
////    char **result = NULL;
////    int count = 0;
////    char * digits = "23";
////    int N = strlen(digits);
////    char *s = (char *)malloc(sizeof(char) * (N + 1));
////    getCombinations(0, digits, &result, &count, s);
////    int i;
////    for (i = 0; i < count; i++) {
////        printf("%s\n", result[i]);
////    }
//
//
//    int count;
//    char *digits = "23";
//    char ** result;
//    result = letterCombinations(digits, &count);
//    int i;
//    for (i = 0; i < count; i++) {
//        printf("%s\n", result[i]);
//    }
//
//    return 0;
//}