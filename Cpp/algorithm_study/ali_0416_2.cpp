/**
 * 2021/4/16 阿里笔试题 2
 *
 * 最大可获得美味值
 *
 * 题目：
 * 国王在 1 号城堡，每个城堡有火锅且有美味值。
 * 现在共有 n 个城堡，每个城堡都有一个美味值 ai，吃火锅不花时间。
 * n-1 条双向通道，经过通道会花费时间。
 * 现在给出一个图，求在 T 时间内，国王能获得的最大美味值。
 * 并且要求，国王最后要回到原点。
 *
 * 输入：n 个城堡，每个城堡的美味值，输入 n-1 条通道以及对应的花费时间，可用时间 T
 * 输出：最大美味值
 *
 * 个人理解：
 * 要求回到原点，这明显就是找回环。
 * 所有顶点相加，就是可获得美味值。
 * 但是必须满足花费时间在可允许范围内。
 * 所以，最大的难点在于，如何找出所有的回环？
 * 如果能找出所有的回环，就能通过枚举法找出最大可获得美味值。
 */

#include<iostream>
#include <vector>
using namespace std;

void test_0() {
    int n;
    int *deliciousValue;
    int i, T;

    // 输入
    cin >> n;   // 城堡数量
    deliciousValue = new int[n];
    for (i = 0; i < n; i++) {
        cin >> deliciousValue[i]; // 城堡美味值
    }
    vector<vector<int>> dis(n-1);
    for (i = 0; i < n-1; i++) {
        dis[i].resize(3);
        cin >> dis[i][0] >> dis[i][1] >> dis[i][2]; // 路径花费时间
    }
    cin >> T;   // 允许时间

    // TODO
}

int main() {



    return 0;
}