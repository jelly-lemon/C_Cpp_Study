/** 放大像素
 *
 *
第一个数字：矩阵大小，第二个数字：放大倍数
后面就是该矩阵。


输入：
2 2
0 1
1 0

输出：
0 0 1 1
0 0 1 1
1 1 0 0
1 1 0 0

输入：
3 3
1 0 1
0 0 0
1 0 1

 输出：
1 1 1 0 0 0 1 1 1
1 1 1 0 0 0 1 1 1
1 1 1 0 0 0 1 1 1
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
1 1 1 0 0 0 1 1 1
1 1 1 0 0 0 1 1 1
1 1 1 0 0 0 1 1 1
 */

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> arr;

    for (int i = 0; i < N; i++) {
        vector<int> tArr;
        for (int j = 0; j < N; j++) {
            int n;
            cin >> n;
            for (int k = 0; k < K; k++) {
                tArr.push_back(n);
            }
        }
        for (int k = 0; k < K; k++) {
            arr.push_back(tArr);
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}