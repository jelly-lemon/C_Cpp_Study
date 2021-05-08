/*
 * 假设你有一个数组，其中第 i 个元素是股票在第 i 天的价格。
你有一次买入和卖出的机会。（只有买入了股票以后才能卖出）。请你设计一个算法来计算可以获得的最大收益。

 输入：
 [1,4,2]
 输出：
 3

 碎言碎语：所有结果都给出来了，让你去挑一个最好的买入卖出日期，看起来很好玩美。
 但现实世界是你肯本不知道明天的股价是多少。
 */
#include <vector>
using namespace std;

/**
 * 思路 1：暴力法，时间复杂度是指数阶
 */
int maxProfit(vector<int>& prices) {
    // write code here
}


/**
 * 思路 2：动态规划，使用 迭代 + 自底向上
 *
 * 运行时间：3ms
超过37.52%用C++提交的代码
占用内存：352KB
超过93.16%用C++提交的代码
 */
int maxProfit_1(vector<int>& prices) {
    int len = prices.size();
    if (len == 0)
        return 0;

    int *dp = new int[len];
    dp[0] = 0;
    int min = prices[0];
    for (int i = 1; i < len; i++) {
        int r1 = prices[i] - min;
        int r2 = dp[i-1];
        dp[i] = r1 > r2 ? r1 : r2;
        if (prices[i] < min)
            min = prices[i];
    }

    return dp[len-1];
}

/**
 * 思路 3：根据递推公式，使用 递归 + 自顶向下 计算
 */
int maxProfit_2(vector<int>& prices) {
    if (prices.size() == 0)
        return 0;
}

/**
 * 思路 4：根据递推公式，使用 迭代 + 自顶向下 计算
 */
int maxProfit_3(vector<int>& prices) {
    if (prices.size() == 0)
        return 0;
}

