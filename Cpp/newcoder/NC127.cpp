

string LCS(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    int dp[len1+1][len2+1] = {0};

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
        }
    }
    int subLen = dp[len1][len2];

    // TODO 找子串
}