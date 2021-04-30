/*
 给定一个 n * m 的矩阵 a，从左上角开始每次只能向右或者向下走，
 最后到达右下角的位置，路径上所有的数字累加起来就是路径和，
 输出所有的路径中最小的路径和。

 测试用例：[[1,3,5,9],[8,1,3,4],[5,0,6,1],[8,8,4,0]] --> 12
 */

int getMin(vector<vector<int> >& matrix, int p_i, int p_j, int value) {
    int n = matrix.size();
    if (n == 0)
        return 0;
    int m = matrix[0].size();
    if (p_i == n-1 and p_j == m-1) {
        return value + matrix[p_i][p_j];
    } else {
        value += matrix[p_i][p_j];
        if (p_i < n-1 && p_j < m-1) {
            int a1 = getMin(matrix, p_i+1, p_j, value);
            int a2 = getMin(matrix, p_i, p_j+1, value);
            return a1 > a2 ? a2:a1;
        } else {
            if (p_i == n-1)
                return getMin(matrix, p_i, p_j+1, value);
            if (p_j == m-1)
                return getMin(matrix, p_i+1, p_j, value);
        }
    }
    return 0;
}

/**
 * 运行超时
 * 用例通过率：0.00%
 */
int minPathSum(vector<vector<int> >& matrix) {
    // write code here
    return getMin(matrix, 0, 0, 0);
}