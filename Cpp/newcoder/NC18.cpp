/*
 * 有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于300。
 输入：[[1,2,3],[4,5,6],[7,8,9]],3
 返回值：[[7,4,1],[8,5,2],[9,6,3]]
 */

/**
 * 运行时间：6ms
超过90.39% 用C++提交的代码
占用内存：780KB
超过74.08%用C++提交的代码
 */
vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
    vector<vector<int> > newMat;
    for(int j = 0; j < n; j++) {
        vector<int> tVec;
        for (int i = n-1; i >= 0; i--) {
            tVec.push_back(mat[i][j]);
        }
        newMat.push_back(tVec);
    }
    return newMat;
}