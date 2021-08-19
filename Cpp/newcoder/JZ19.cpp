/**
 JZ19 顺时针打印矩阵

 描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
[[1,2,3,4],
[5,6,7,8],
[9,10,11,12],
[13,14,15,16]]
则依次打印出数字
[1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]

 示例1
输入：
[[1,2],[3,4]]

 返回值：
[1,2,4,3]


 有难度，要考虑各种边界值
 */


/**
    [[1]]:
    [[1],[2],[3],[4],[5]]:
    */
vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> r;

    if (matrix.size() == 0) {
        return r;
    }

    if (matrix.size() == 1) {
        return matrix[0];
    }

    if (matrix[0].size() == 1) {
        for (int i = 0; i < matrix.size(); i++) {
            r.push_back(matrix[i][0]);
        }
        return r;
    }


    int row = matrix.size();    // 总行数
    int col = matrix[0].size();    // 总列数

    int rowMoveLen = row - 1;    // 该轮某个方向遍历个数
    int colMoveLen = col - 1;
    int times = min(row / 2 + 1, col/2 + 1);        // 共几轮


    for (int k = 0; k < times; k++) {
        // 矩阵为奇数行和列
        if (rowMoveLen == 0 && colMoveLen == 0) {
            r.push_back(matrix[row/2][col/2]);
        }

        // 右
        for (int j = 0; j < colMoveLen; j++) {
            r.push_back(matrix[k][k+j]);
        }
        // 下
        for (int i = 0; i < rowMoveLen; i++) {
            r.push_back(matrix[i+k][col-1-k]);
        }
        // 左
        for (int j = 0; j < colMoveLen; j++) {
            r.push_back(matrix[row-1-k][col-1-k-j]);
        }
        // 上
        for (int i = 0; i < rowMoveLen; i++) {
            r.push_back(matrix[row-1-k-i][k]);
        }
        rowMoveLen -= 2;
        colMoveLen -= 2;
    }

    return r;
}