/*
 * 给一个01矩阵，1代表是陆地，0代表海洋， 如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。
岛屿: 相邻陆地可以组成一个岛屿（相邻:上下左右） 判断岛屿个数。
 备注：
 01矩阵范围<=200*200

 输入：
 [[1,1,0,0,0],[0,1,0,1,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,1,1,1]]
 返回值：
 3

 个人感觉：很难，不知道从何下手
 */


/**
 * 思路 1：遍历二维数组，遇到 1 时 count++，表示岛屿数量，然后把该 1 周围的全部 1 置为 0
 * 接着再继续遍历
 *
 * 运行时间：18ms
超过20.49% 用C++提交的代码
占用内存：760KB
超过45.33%用C++提交的代码
 */
int solve(vector<vector<char> >& grid) {
    // write code here
    int nRow, nCol;
    int count = 0;
    nRow = grid.size();
    nCol = grid[0].size();
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (grid[i][j] == '1') {
                count++;
                search(grid, i, j);
            }
        }
    }
    return count;
}

void search(vector<vector<char> >& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
        return ;
    }
    if (grid[i][j] == '1') {
        grid[i][j] = '0';
    } else if (grid[i][j] == '0'){
        return ;
    }

    search(grid, i+1, j);
    search(grid, i-1, j);
    search(grid, i, j+1);
    search(grid, i, j-1);
}