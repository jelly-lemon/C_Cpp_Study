/*
 给定一个数组arr，返回子数组的最大累加和
例如，arr = [1, -2, 3, 5, -2, 6, -1]，所有子数组中，[3, 5, -2, 6]可以累加出最大的和12，所以返回12.
题目保证没有全为负数的数据
[要求]
时间复杂度为O(n)，空间复杂度为O(1)
 */

/**
 * 暴力法
 超时
 */
int maxsumofSubarray(vector<int>& arr) {
    // write code here

    int max = 0;
    int curVal = 0;
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            continue;
        }
        curVal = arr[i];
        for (int j = i+1; j < len; j++) {
            if(curVal+arr[j] <= arr[j]) {
                break;
            } else {
                curVal += arr[j];
                if (max < curVal) {
                    max = curVal;
                }
            }
        }
    }
    return max;
}

/**
 * 思路 2：动态规划
 *
 * 运行时间：56ms
超过53.88%用C++提交的代码
占用内存：3264KB
超过19.97%用C++提交的代码
 */
int maxsumofSubarray(vector<int>& arr) {
    int len = arr.size();
    if (len == 0)
        return 0;
    int dp[len+1];
    dp[0] = 0;

    for (int i = 1; i <= len; i++) {
        int r1 = dp[i-1];   // 不选择第 i 个数
        // 选择第 i 个数
        // 【易错点】选择的子数组必须是连续的
        int r2 = 0;
        // 判断前面一个数是否大于 0
        if (arr[i-2] >= 0) {
            // 如果 >= 0，则可以累加（都是正数，累加和必然比一个数大）
            r2 = dp[i-1] + arr[i-1];
        } else {
            // 如果 < 0，再判断前 i-1 个数的最大累计和与前面一个数的和是否 > 0，> 0 就说明值得加，因为最终还是为正嘛，就代表赚了
            // 但如果 < 0，就表示前面的最大累加和还敌不过前面一个负数的败家，果断抛弃败家子。
            if (dp[i-1] + arr[i-2] > 0) {
                r2 = dp[i-1] + arr[i-1];
            } else {
                r2 = arr[i-1];
            }
        }
        dp[i] = r1 > r2 ? r1 : r2;
    }

    return dp[len];
}