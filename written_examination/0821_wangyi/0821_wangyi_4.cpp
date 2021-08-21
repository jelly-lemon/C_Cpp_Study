#include <vector>
#include <iostream>

using namespace std;

/**
 *
 返回 -1 骗分  16.67%

 航海探险

 从 (0,0) 出发，到矩阵右下角，
 0 表示水，花费 2
 1 表示陆地，花费 1
 2 表示障碍，无法通过
 这可以上下左右移动
 求最小代价，不可达时返回 -1

 输入：
 [[1,1,1,1,0],[0,1,0,1,0],[1,1,2,1,1],[0,2,0,0,1]]

 输出：
 7
 */

int getMinCost(vector<vector<int> > input, int i, int j) {
    if (i == input.size()-1 && j == input[0].size()-1) {
        cout << input[i][j] << endl;
        if (input[i][j] == 0) {
            return 2;
        } else if (input[i][j] == 1) {
            return 1;
        } else {
            return -1;
        }
    }

    int minCost = -1;
    int cost = -1;
    // 上
    if (i-1 >= 0 && input[i-1][j] != -1 && input[i-1][j] != 2) {
        if (input[i-1][j] == 1) {
            input[i-1][j] = -1;
            cost = getMinCost(input, i-1, j);
            if (cost != -1) {
                cost += 1;
            }
        } else if (input[i-1][j] == 0) {
            input[i-1][j] = -1;
            cost = getMinCost(input, i-1, j);
            if (cost != -1) {
                cost += 2;
            }
        }

        if (cost != -1) {
            if (minCost == -1) {
                minCost = cost;
            } else if (minCost < cost) {
                minCost = cost;
            }
        }
    }


    // 下
    if (i+1 < input.size() && input[i+1][j] != -1 && input[i+1][j] != 2) {
        if (input[i+1][j] == 1) {
            input[i+1][j] = -1;
            cost = getMinCost(input, i+1, j);
            if (cost != -1) {
                cost += 1;
            }
        } else if (input[i+1][j] == 0) {
            input[i+1][j] = -1;
            cost =  getMinCost(input, i+1, j);
            if (cost != -1) {
                cost += 2;
            }
        }

        if (cost != -1) {
            if (minCost == -1) {
                minCost = cost;
            } else if (minCost < cost) {
                minCost = cost;
            }
        }
    }

    // 左
    if (j-1 >= 0 && input[i][j-1] != -1 && input[i][j-1] != 2) {
        if (input[i][j-1] == 1) {
            input[i][j-1] = -1;
            cost =  getMinCost(input, i, j-1);
            if (cost != -1) {
                cost += 1;
            }
        } else if (input[i][j-1] == 0) {
            input[i][j-1] = -1;
            cost = getMinCost(input, i, j-1);
            if (cost != -1) {
                cost += 2;
            }
        }

        if (cost != -1) {
            if (minCost == -1) {
                minCost = cost;
            } else if (minCost < cost) {
                minCost = cost;
            }
        }
    }

    // 右
    if (j+1 >= 0 && input[i][j+1] != -1 && input[i][j+1] != 2) {
        if (input[i][j+1] == 1) {
            input[i][j+1] = -1;
            cost =  getMinCost(input, i, j+1);
            if (cost != -1) {
                cost += 1;
            }
        } else if (input[i][j+1] == 0) {
            input[i][j+1] = -1;
            cost =  getMinCost(input, i, j+1);
            if (cost != -1) {
                cost += 2;
            }
        }

        if (cost != -1) {
            if (minCost == -1) {
                minCost = cost;
            } else if (minCost < cost) {
                minCost = cost;
            }
        }
    }

    return minCost;
}

int minSailCost(vector<vector<int> >& input) {
    // write code here
    int minCost = getMinCost(input, 0, 0);

    return minCost;
}

int main() {
    vector<vector<int> > input;
    vector<int> v1 = {1,1,1,1,0};
    vector<int> v2 = {0,1,0,1,0};
    vector<int> v3 = {1,1,2,1,1};
    vector<int> v4 = {0,2,0,0,1};
    input.push_back(v1);
    input.push_back(v2);
    input.push_back(v3);
    input.push_back(v4);

    int minCost = minSailCost(input);
    cout << minCost;

    return 0;
}