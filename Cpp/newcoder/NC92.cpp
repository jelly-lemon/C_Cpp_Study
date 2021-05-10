/*
 * 给定两个字符串str1和str2，输出两个字符串的最长公共子序列。如果最长公共子序列为空，则输出-1。
 输入：
 "1A2C3D4B56","B1D23CA45B6A"
 输出：
 "123456"
 说明：
 "123456"和“12C4B6”都是最长公共子序列，任意输出一个。
 1 <= str1, str2 <= 5000

 个人感觉：很难
 要与最长公共字串区别开来
 */

#include <string>
using namespace std;

/**
 * 思路 1：暴力法，挨个比对
 */
string LCS(string s1, string s2) {

}

/**
 * 思路 2：动态规划
 * 构建 c[i][j] 表需要 Θ(mn)，输出 1 个 LCS 的序列需要 Θ(m+n)
 * 【难点】找到了最长子序列的长度，如何找出子序列
 */
string LCS_1(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();

    int dp[len1+1][len2+2];
//    int **dp = new int* [len1+1];
    // 这里 len1+1 很容易忘记，容易误写成 len1
    for (int i = 0; i < len1+1; i++) {
//        dp[i] = new int[len2+1];
        dp[i][0] = 0;
    }
    for (int j = 0; j < len2+1; j++) {
        dp[0][j] = 0;
    }

    // 找出最大长度
    for (int m = 1; m <= len1; m++) {
        for (int n = 1; n <= len2; n++) {
            if (s1[m-1] == s2[n-1]) {
                dp[m][n] = dp[m-1][n-1] + 1;
                continue;
            } else {
                int r1 = dp[m-1][n];
                int r2 = dp[m][n-1];
                dp[m][n] = r1 > r2 ? r1:r2;
            }
        }
    }
    if (dp[m][n] == -1) {
        return -1;
    }
    // TODO 找出该序列
    string s;
    int count = 1;
    for (int m = 1; m <= len1; m++) {
        for (int n = 1; n <= len2; n++) {
            if (dp[m][n] == count) {
                s += s1[m-1];
                count++;
                break;
            }
        }
    }
    return s;
}