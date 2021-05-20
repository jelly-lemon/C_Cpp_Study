/*
 * 给定两个字符串str1和str2，再给定三个整数ic，dc和rc，
 * 分别代表插入、删除和替换一个字符的代价，
 * 请输出将str1编辑成str2的最小代价。
 *
 * 难度：个人感觉很难，感觉很复杂，脑袋想不过来

 "xhcjhjsrjamxkjdbiqnqjxfsugywrpceyuniviqdynpipfytbaijwsjnhynxnwzydyxmrqlxnygttbaqsneejojukjkkxrsxyywmnsgcuxbnnavmytbthosfuhzytripxthaciiupodunllqz",
 "xmhjrtsajahxkjialbtfgrikbepnwqnjrrxfsssgyvrnrmocxuqshmvwqsphyqndipxabbsaijjbnxnxjnywndyxscmrlvnarvtgbwaqgsgjeegazofjmuiocjlxwemyyywmsgyuxnmjmytvybgyghcxtsfuhzyqzhdhsdviokpmstgciaukbkpniotddnvmqz",
 6477,7414,1063
 输出：
 396035
 */

/**
 * 测试用例未通过，不知道错在哪里
 */
int minEditCost(string str1, string str2, int ic, int dc, int rc) {
    // write code here
    int m = str1.size();
    int n = str2.size();
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i-1][0] + dc;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j-1] + ic;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                // 插入
                int r1 = 0x7fffffff;
                if (i < j) {
                    r1 = dp[i][j-1] + ic;
                }
                // 删除
                int r2 = 0x7fffffff;
                if(i > j) {
                    r2 = dp[i-1][j] + dc;
                }

                int r3 = 0x7fffffff;// 替换
                int r4 = 0x7fffffff;// 删除+插入
                if (i == j) {
                    r3 = dp[i-1][j-1] + rc;// 替换
                    r4 = dp[i-1][j-1] + dc + ic;// 删除+插入
                }


                r1 = min(r1, r2);
                r3 = min(r3, r4);
                int minValue = min(r1, r3);
                dp[i][j] = minValue;
            }
        }
    }

    return dp[m][n];
}

/**
 * 思路 1：动态规划
 * 时间复杂度：O(mn)
 * 空间复杂度：O(mn)
 *
 *运行时间：13ms
超过50.43% 用C++提交的代码
占用内存：5092KB
超过74.19%用C++提交的代码
 */
int minEditCost(string str1, string str2, int ic, int dc, int rc) {
    // write code here
    int m = str1.size();
    int n = str2.size();
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i-1][0] + dc;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j-1] + ic;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                // TODO 不理解为什么每次都要考虑 4 种情况，有些情况不是不能插入删除等吗？
                int r1 = dp[i][j-1] + ic; // 插入
                int r2 = dp[i-1][j] + dc; // 删除
                int r3 = dp[i-1][j-1] + rc;// 替换
                int r4 = dp[i-1][j-1] + dc + ic;// 删除+插入

                r1 = min(r1, r2);
                r3 = min(r3, r4);
                int minValue = min(r1, r3);
                dp[i][j] = minValue;
            }
        }
    }

    return dp[m][n];
}