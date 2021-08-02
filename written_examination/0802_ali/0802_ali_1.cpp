
/**
牛牛逃出监狱，出口在右下角，起点在 0

输入：
2 （数据数量）
3 3 （数组行、列）
0 1 5
1 1 6
2 3 4
2 2 （数组行、列）
0 1
1 1

输出：
YES
NO

for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */

#include <iostream>
#include <vector>
using namespace std;


void isOK(vector<vector<int>> &arr) {
    int startI = -1, startJ = -1;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j] == 0) {
                startI = i;
                startJ = j;
                break;
            }
        }
        if (startI != -1) {
            break;
        }
    }
    int time = arr[arr.size()-1][arr[0].size()-1];
    int minLen = (arr.size() - (startI+1)) + (arr[0].size()-(startJ+1));
    if (time > minLen) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main() {
    vector<vector<int>> arr;

    int n;
    cin >> n;

    for (int iN = 0; iN < n; iN++) {
        arr.clear();

        int row, col;
        cin >> row >> col;
        for (int i = 0; i < row; i++) {
            vector<int> tVec;
            for (int j = 0; j < col; j++) {
                int a;
                cin >> a;
                tVec.push_back(a);
            }
            arr.push_back(tVec);
        }

        isOK(arr);
    }



    return 0;
}