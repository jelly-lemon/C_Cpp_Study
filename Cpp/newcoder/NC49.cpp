/**
    运行时间：3ms
超过75.38% 用C++提交的代码
占用内存：520KB
超过39.64%用C++提交的代码
    【思路】字串一定是连续的
     */
int longestValidParentheses(string s) {
    //
    // dp[i] 表示以 s[i] 结尾符合要求的子串
    //
    vector<int> dp(s.size(), 0);
    int maxValue = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] ==')') {
            //
            // 单配对 () 的情况
            //
            if (s[i-1] == '(') {
                if (i - 2 > 0 && dp[i-2] > 0) {
                    dp[i] = dp[i-2] + 2;
                } else {
                    dp[i] = 2;
                }
            } else {
                //
                // 跨配对的情况：(())
                //
                int prev = i-1-dp[i-1];
                if (s[prev] == '(') {
                    if (prev - 1 > 0 && dp[prev-1] > 0) {
                        dp[i] = dp[prev-1] + dp[i-1] + 2;
                    } else {
                        dp[i] = dp[i-1] + 2;
                    }
                }
            }
            if (dp[i] > maxValue) {
                maxValue = dp[i];
            }
        }
    }

    return maxValue;
}