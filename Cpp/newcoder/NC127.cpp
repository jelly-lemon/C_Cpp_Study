/*
 * 给定两个字符串str1和str2,输出两个字符串的最长公共子串
题目保证str1和str2的最长公共子串存在且唯一。

 1 <= str1, str2 <= 5000
 */


/*
 * 动态规划
 *
 * 运行时间：964ms
超过18.54%用C++提交的代码
占用内存：98096KB
超过53.94%用C++提交的代码
 */
string LCS(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    int dp[len1+1][len2+1];
    for (int i = 0; i < len1+1; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j < len2+1; j++) {
        dp[0][j] = 0;
    }
    int lastPos = 0;
    int maxLen = 0;
    for (int m = 1; m <= len1; m++) {
        for (int n = 1; n <= len2; n++) {
            string s1(str1, m-1-dp[m-1][n-1], dp[m-1][n-1]+1);
            string s2(str2, n-1-dp[m-1][n-1], dp[m-1][n-1]+1);
            if (s1 == s2) {
                dp[m][n] = dp[m-1][n-1] + 1;
            } else {
                int r1 = dp[m][n-1];
                int r2 = dp[m-1][n-1];
                dp[m][n] = r1 > r2 ? r1 : r2;
            }
            if (dp[m][n] > maxLen) {
                maxLen = dp[m][n];
                lastPos = m-1;
            }
        }
    }

    // TODO 【难点】找到子串的起始下标
    string s(str1, lastPos-maxLen+1, maxLen);
    return s;
}