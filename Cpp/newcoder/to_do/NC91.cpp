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