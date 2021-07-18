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
 只要能够在两个字符串中找出这两个序列就行，不一定是连续的
 */

#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;


/**
 * 运行时间：15ms
超过37.95% 用C++提交的代码
占用内存：9464KB
超过61.86%用C++提交的代码
 *
 *
 * 思路 ：动态规划
 * 构建 c[i][j] 表需要 Θ(mn)，输出 1 个 LCS 的序列需要 Θ(m+n)
 * 【难点】找到了最长子序列的长度，如何找出子序列
 */
string LCS(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();

    //
    // 动态规划数组要比原始数据多一行，多一列，用来初始化
    //
    int dp[len1+1][len2+1];
    memset(dp, 0, sizeof(int)*(len1+1)*(len2+1));

    //
    // 找出最大长度
    //
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

    //
    // 找出该序列
    //
    string maxSubStr;
    int i = len1, j = len2;
    while(dp[i][j] > 0) {
        //
        // 【易错点】dp数组和原字符数组小标要分清
        //
        int s_i = i-1;
        int s_j = j-1;
        if (s1[s_i] == s2[s_j]) {
            //
            // 该位置两个字符相等，那就是最长子序列的一部分
            //
            printf("s1[%d]=%d, s2[%d]=%d\n", s_i, s1[s_i], s_j, s2[s_j]);
            maxSubStr += s1[s_i];
            i--, j--;
        } else {
            if (dp[i-1][j] == dp[i][j-1]) {
                //
                // 此时：上 == 左
                // 这里既可以选左边，也可以选上边，但整体必须保持一致
                // 我选上
                //
                i--;
            } else if (dp[i-1][j] > dp[i][j-1]){
                //
                // 此时：上 > 左，谁大就走哪边
                //
                i--;
            } else {
                //
                // 此时：左 > 上
                //
                j--;
            }
        }
    }
    reverse(maxSubStr.begin(), maxSubStr.end());

    //
    // 如果为空串，返回 -1
    //
    if (maxSubStr.empty()) {
        maxSubStr = "-1";
    }

    return maxSubStr;
}

void test_0() {
    string maxSubStr = LCS("13456778","357486782");
    cout << maxSubStr << endl;
}

int main() {
    test_0();

    return 0;
}
