/**
 * JZ65 矩阵中的路径
 *
 描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
 例如
    a   b   c   e
    s   f   c   s
    a   d   e   e


 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

示例1
输入：[[a,b,c,e],[s,f,c,s],[a,d,e,e]],"abcced"
返回值：true

 示例2
输入：[[a,b,c,e],[s,f,c,s],[a,d,e,e]],"abcb"
返回值：false

 备注：
0 <= matrix.length <= 200
0 <= matrix[i].length <= 200
 */

/**
     *
     运行时间：5ms
超过61.28% 用C++提交的代码
占用内存：548KB
超过25.13%用C++提交的代码
     */
bool hasPath(vector<vector<char> >& matrix, string word) {
    // write code here

    // 找可能的起点
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (word[0] == matrix[i][j]) {
                cout << "----" << endl;
                cout << i << " ," << j << " :" << word[0] << endl;
                // 从该位置进行查找
                matrix[i][j] = '0';
                bool rt = dfs(matrix, i, j, word, 1);
                if (rt) {
                    return rt;
                }
                matrix[i][j] = word[0];
            }
        }
    }

    return false;
}

bool dfs(vector<vector<char> >& matrix, int i, int j, string &word, int count) {
    // count 表示已找到的匹配字符数量
    if (count == word.size()) {
        return true;
    }

    // 上
    if (i-1 >= 0) {
        if (matrix[i-1][j] == word[count] && matrix[i-1][j] != '0') {
            matrix[i-1][j] = '0';
            cout << i-1 << " ," << j << " :" << word[count] << endl;
            bool r1 = dfs(matrix, i-1, j, word, count+1);
            if (r1) {
                return true;
            }
            matrix[i-1][j] = word[count];
        }
    }

    if (i+1 < matrix.size()) {
        // 下
        if (matrix[i+1][j] == word[count]&& matrix[i+1][j] != '0') {
            matrix[i+1][j] = '0';
            cout << i+1 << " ," << j << " :" << word[count] << endl;
            bool r1 = dfs(matrix, i+1, j, word, count+1);
            if (r1) {
                return true;
            }
            matrix[i+1][j] = word[count];
        }
    }

    if (j-1 >= 0) {
        // 左
        if (matrix[i][j-1] == word[count]&& matrix[i][j-1] != '0') {
            matrix[i][j-1] = '0';
            cout << i << " ," << j-1 << " :" << word[count] << endl;
            bool r1 = dfs(matrix, i, j-1, word, count+1);
            if (r1) {
                return true;
            }
            matrix[i][j-1] = word[count];
        }
    }

    if (j+1 < matrix[0].size()) {
        // 右
        if (matrix[i][j+1] == word[count]&& matrix[i][j+1] != '0') {
            matrix[i][j+1] = '0';
            cout << i << " ," << j+1 << " :" << word[count] << endl;
            bool r1 = dfs(matrix, i, j+1, word, count+1);
            if (r1) {
                return true;
            }
            matrix[i][j+1] = word[count];
        }
    }

    return false;
}