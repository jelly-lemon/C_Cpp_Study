/**
副对角线输出二维数组
*/
#include <vector>
#include <iostream>
using namespace std;

void test_0() {
    int nums[4][4] = {{1,2,3,4},{6,7,8,9}, {11,12,13,14}, {16,17,18,19}};
    int m = 4, n = 4;

//    int nums[3][4] = {{1,2,3,4},{5,6,7,8}, {9,10,11,12}};
//    int m = 3, n = 4;

//    int nums[4][3] = {{1,2,3},{4,5,6}, {7,8,9}, {10,11,12}};
//    int m = 4, n = 3;

    // 正方形
    // 上三角
    for (int j = n-1; j > 0; j--) {
        int k = j;
        for (int i = 0; i < m; i++) {
            if (k < n) {
                cout << nums[i][k] << " ";
            } else {
                break;
            }
            k++;
        }
        cout << endl;
    }
    // 对角线
    // 【易错点】二维数组可能列更多或者宽更多，输出对角线时要考虑到
    for (int i = 0; i < m && i < n; i++) {
        cout << nums[i][i] << " ";
    }
    cout << endl;

    // 下三角
    for (int i = 1; i < m; i++) {
        int q = i;
        for (int j = 0; j < n; j++) {
            if (q < m) {
                cout << nums[q][j] << " ";
            } else {
                break;
            }
            q++;
        }
        cout << endl;
    }
}

int main() {
    test_0();

    return 0;
}