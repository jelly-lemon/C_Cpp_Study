/**
     * 运行时间：10ms
超过79.56% 用C++提交的代码
占用内存：424KB
超过57.12%用C++提交的代码

 递推公式：dp[aim] = min{dp[aim-arr[i] + 1}
     */
int minMoney(vector<int>& arr, int aim) {
    // write code here
    if (aim == 0) {
        return 0;
    }
    // 【特别容易忘记】动态规划结果数组要比原数据长度大 1
    int dpLen = aim+1;
    int dp[dpLen];
    memset(dp, 0, sizeof(int)*(dpLen));
    dp[0] = 0;

    for (int iAim = 1; iAim <= aim; iAim++) {
        int min = 0x7FFFFFFF;
        for(auto &n:arr) {
            if (iAim-n >= 0) {
                if (dp[iAim-n] != -1) {
                    int tMin = dp[iAim-n]+1;
                    if (tMin != -1 && min > tMin) {
                        min = tMin;
                    }
                }
            }
        }
        if (min == 0x7FFFFFFF) {
            dp[iAim] = -1;
        } else {
            dp[iAim] = min;
        }
    }

    if (dp[aim] == 0) {
        return -1;
    }
    return dp[aim];
}