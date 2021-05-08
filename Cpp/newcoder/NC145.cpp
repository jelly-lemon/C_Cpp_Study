/*
 * 已知一个背包最多能容纳物体的体积为V
现有n个物品第i个物品的体积为vi，第i个物品的重量为 wi
求当前背包最多能装多大重量的物品

 输入：
 10,2,[[1,3],[10,4]]
 输出：
 4
 说明：
 第一个物品的体积为1，重量为3，第二个物品的体积为10，重量为4。只取第二个物品可以达到最优方案，取物重量为4

 注意：
 1 <= V <= 200
 1 <= n <= 200
 1 <= vi <= 200
 1 <= wi <= 200
 */

#include <vector>
using namespace std;

/**
 * 思路 1：动态规划
 *
 * 运行时间：10ms
超过20.84%用C++提交的代码
占用内存：736KB
超过1.94%用C++提交的代码（第一次遇到这么低的）
 */
int knapsack(int V, int n, vector<vector<int> >& vw) {
    // int dp[V+1][n+1] = {0};
    // variable-sized object may not be initialized
    // 不允许对变长数组进行初始化吗？
    int dp[V+1][n+1];
    for (int i = 0; i < V+1; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j < n+1; j++) {
        dp[0][j] = 0;
    }

    for (int v = 1; v <= V; v++) {
        for (int num = 1; num <= n; num++) {
            int r1 = dp[v][num-1];  // 不装第 num 个物品
            // 【易错点】要先判断背包能不能装下第 num 个物品，能装下才装，不然 v-vw[num-1][0] 就变成负数了
            int r2 = 0;
            // 判断能够装下第 num 个物品
            if (v-vw[num-1][0] >= 0) {
                r2 = dp[v-vw[num-1][0]][num-1] + vw[num-1][1];
            }
            dp[v][num] = r1 > r2 ? r1 : r2;
        }
    }
    return dp[V][n];
}