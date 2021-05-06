/*
 给定一个 n * m 的矩阵 a，从左上角开始每次只能向右或者向下走，
 最后到达右下角的位置，路径上所有的数字累加起来就是路径和，
 输出所有的路径中最小的路径和。

 1≤n,m≤2000
 1≤数组中的元素≤100

 测试用例：[[1,3,5,9],[8,1,3,4],[5,0,6,1],[8,8,4,0]] --> 12
 [1,3,5,9]
 [8,1,3,4]
 [5,0,6,1]
 [8,8,4,0]


 */
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


/**
 * 思路 1：枚举法(递归写法)，从起点出发，找出所有路径
 * 结果运行超时
 *
 * @param matrix 矩阵
 * @param p_i 当前行标
 * @param p_j 当前列标
 * @param value 当前累加和
 * @return 最小累加和
 */
int getMin(vector<vector<int> >& matrix, int p_i, int p_j, int value, vector<int> curPath) {
    int n = matrix.size();
    if (n == 0)
        return 0;
    int m = matrix[0].size();
    curPath.push_back(matrix[p_i][p_j]);    // 添加当前元素到 curPath 末尾

    // 走到右下角
    if (p_i == n-1 and p_j == m-1) {
        for (int &a : curPath) {
            cout << a << " ";
        }
        value += matrix[p_i][p_j];
        cout << ", value=" << value << endl;
        return value;
    }

    // 打印当前路径
    for (int &a : curPath) {
        cout << a << " ";
    }
    cout << endl;

    // 还在矩阵中间
    value += matrix[p_i][p_j]; // 累加当前位置上的值
    if (p_i < n-1 && p_j < m-1) {
        int a1 = getMin(matrix, p_i+1, p_j, value, curPath);
        int a2 = getMin(matrix, p_i, p_j+1, value, curPath);
        return a1 > a2 ? a2:a1;
    } else {
        // 走到了最后一行
        if (p_i == n-1)
            return getMin(matrix, p_i, p_j+1, value, curPath);
        // 走到了最后一列
        if (p_j == m-1)
            return getMin(matrix, p_i+1, p_j, value, curPath);
    }
    return 0;
}

/**
 * 调用思路 1 的函数
 *
 * @param matrix
 * @return
 */
int minPathSum(vector<vector<int> >& matrix) {
    // write code here
    vector<int> curPath;
    return getMin(matrix, 0, 0, 0, curPath);
}

/**
 * 测试思路 1
 */
void test_0() {
    vector<vector<int> > matrix;
    vector<int> t1 = {1,3,5,9};
    vector<int> t2 = {8,1,3,4};
    vector<int> t3 = {5,0,6,1};
    vector<int> t4 = {8,8,4,0};
    matrix.push_back(t1);
    matrix.push_back(t2);
    matrix.push_back(t3);
    matrix.push_back(t4);
    int min = minPathSum(matrix);
    cout << "min=" << min << endl;
}

/**
 * 思路 3：枚举法(迭代写法)
 */
int getMin_3() {
    return 0;
}

/**
 * 思路 2：动态规划
 * 运行时间：3ms
超过78.95%用C++提交的代码
占用内存：404KB
超过47.79%用C++提交的代码
 *
 * @param matrix
 * @param dp
 * @return
 */
int getMin_1(vector<vector<int> >& matrix, int **dp) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 and j == 0) {
                dp[i][j] = matrix[i][j];
            } else if (i == 0) {
                dp[i][j] = dp[i][j-1] + matrix[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j] + matrix[i][j];
            } else {
                int min = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                dp[i][j] = min + matrix[i][j];
            }
            printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
        }
    }
    return dp[n-1][m-1];
}

/**
 * 测试思路 2
 */
void test_1() {
    vector<vector<int> > matrix;
    vector<int> t1 = {1,3,5,9};
    vector<int> t2 = {8,1,3,4};
    vector<int> t3 = {5,0,6,1};
    vector<int> t4 = {8,8,4,0};
    matrix.push_back(t1);
    matrix.push_back(t2);
    matrix.push_back(t3);
    matrix.push_back(t4);
    int **dp = new int *[matrix.size()];
    for (int i = 0; i < matrix.size(); i++) {
        dp[i] = new int[t1.size()];
    }

    int min = getMin_1(matrix, dp);
    cout << "min=" << min << endl;

    delete []dp;
}

int main() {
    test_0();
    return 0;
}
