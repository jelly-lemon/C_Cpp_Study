/*
 * 给定数组arr，设长度为n，输出arr的最长递增子序列。（如果有多个答案，请输出其中字典序最小的）
 * 输入：
 * [2,1,5,3,6,4,8,9,7]
 * 返回值：
 * [1,3,4,8,9]
 *
 * n <= 10^5
 * 1 <= arr_i <= 10^9
 *
 * 【难点】已经求出了最大长度，如何找出最小字典序序列？
 *
 * 有同学爆料：
 * 面试美团以及小米算法岗都考到了，先从求最长子序列长度的题目过渡到这题。
 */

vector<int> LIS(vector<int>& arr) {
    int len = arr.size();
    int dp[len+1];
    dp[0] = 0;
    dp[1] = 1;
    vector<int> v;

    for (int n = 2; n < len+1; n++) {
        int max = 0;
        int max_i;
        for (int i = n-2; i >= 0; i--) {
            if (arr[n-1] > arr[i]) {
                if (dp[i] < max) {
                    max = dp[i];
                    max_i = i;
                }
            }
        }
        dp[n] = max + 1;
    }

    // TODO 如何找出字典序最小的子序列？
    return v;
}


vector<int> LIS(vector<int>& arr) {
    // write code here
    // 动态规划求出最大长度
    int i;
    int arrLen = arr.size();
    int dp[arrLen+1];
    memset(dp, 0, sizeof(int)*(arrLen+1));
    dp[0] = 0, dp[1] = 1;
    for (i = 2; i < arrLen+1; i++) {
        int maxLen = dp[i-1];
        int j = i-1;
        while (dp[j] == maxLen) {
            if (arr[i-1] > arr[j-1]) {
                dp[i] = dp[i-1] + 1;
                break;
            }
            j--;
        }
        if (dp[i] == 0) {
            dp[i] = dp[i-1];
        }
    }

    // 找字典序最长的递增序列
    vector<int> r;
    int maxLen = dp[arrLen];
    for (int iLen = 1; iLen <= maxLen; iLen++) {
        // 找出等于 iLen 的起始位置
        for (int iDP = 1; iDP < arrLen+1; iDP++) {
            if (iLen == dp[iDP]) {
                // 从可选数字中选出最小的
                int minN = arr[iDP-1];
                int lastMax = 0;
                if (!r.empty()) {
                    lastMax = r.back();
                }
                for (; iDP < arrLen+1 && dp[iDP] == iLen; iDP++) {
                    if (minN > arr[iDP-1] && arr[iDP-1] > lastMax) {
                        minn = arr[idp-1];
                    }
                }
                r.push_back(minN);
            }
        }
    }

    return r;
}