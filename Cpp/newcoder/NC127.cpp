

string LCS(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    int **dp = new int* [len1+1];
    for (int i = 0; i < len1+1; i++) {
        dp[i] = new int [len2+1];
    }
    for (int i = 0; i < len1+1; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j < len2+1; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                int r1 = dp[i][j-1];
                int r2 = dp[i-1][j-1];
            }
        }
    }
}