/*
 * 给你一个n（1 <= n <= 10^5），和一个长度为n的数组，
 * 在不同时选位置相邻的两个数的基础上，
 * 求该序列的最大子序列和（挑选出的子序列可以为空）。
 *
 输入：
 3,[1,2,3]
 输出：
 有[],[1],[2],[3],[1,3] 4种选取方式其中[1,3]选取最优，答案为4
 */

/**
 * 思路 2：暴力法
 */
long long subsequence_2(int n, vector<int>& array) {

}

/**
 * 思路 1：动态规划
 */
long long subsequence(int n, vector<int>& array) {
    int len =  array.size();
    int dp[len+1];
    dp[0] = 0;
    int p1, p2;
    p1 = p2 = -1;

    for (int n = 1; n <= len; n++) {
        // 新数小于 0，直接抛弃
        if (array[n-1] <= 0) {
            dp[n] = dp[n-1];
            continue;
        } else {
            // 还没有选择一个数
            if (p1 == -1) {
                p1 = n-1;
                dp[n] = dp[n-1] + array[n-1];
                continue;
            }

            // 还没选择第二个数
            if (p2 == -1) {
                // 两个正数相邻，看谁大
                if (n-1 == p1 + 1) {
                    dp[n] = dp[n-1] > array[n-1] ? dp[n-1] : array[n-1];
                    continue;
                } else {
                    // 两个数不相邻
                    p2 = n-1;    // 标记第二个数
                    dp[n] = dp[n-1] + array[n-1];
                    continue;
                }
            }

            // 新数比两个旧数都小
            if (array[n-1] <= array[p1] and array[n-1] <= array[p2]) {
                // p1 和 p1 中间恰好有一个数
                if (p1+1 == p2) {
                    // 中间数+新数 > 两个旧数
                    if (array[p1+1] + array[n-1] > array[p1] + array[p2]) {
                        p1 = p1+1;
                        p2 = n-1;
                        dp[n] = array[p1+1] + array[n-1];
                        continue;
                    }  else {
                        dp[n] = dp[n-1];
                        continue;
                    }
                } else {
                    dp[n] = dp[n-1];
                    continue;
                }

            }

            // TODO 感觉写得很复杂，好难写
            // 新数比第一个旧数大
            if (array[n-1] > array[p1] and n-1 > p2+1) {
                p1 = p2;
                p2 = n-1;
                dp[n] = dp[n-1] + array[n-1];
                continue;
            }

            // 替换第二个数
            if (array[n-1] > array[p2] )

        }
    }

    return dp[len];
}



