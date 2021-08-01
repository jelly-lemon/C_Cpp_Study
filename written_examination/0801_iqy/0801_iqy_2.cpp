/**
 * 5,6,8,26,50,48,52,55,10,1,2,1,20,5:3
 *
 * 滑动窗口，求平均值，最大增长率
 */


#include <iostream>
#include <vector>
using namespace std;


int main() {
    double maxP = 0;
    //
    // 输入数组
    //
    vector<int> arr;
    int a, k;
    char c;
    while (cin >> a) {
        cin >> c;
        arr.push_back(a);
        if (c == ':') {
            cin >> k;
            break;
        }
    }
    if (k >= arr.size()) {
        return maxP;
    }

    //
    // 计算平均值
    //
    vector<double> ave;
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    ave.push_back(sum/k);
    for (int i = k; i < arr.size(); i++) {
        sum -= arr[i-k];
        sum += arr[i];
        ave.push_back(sum/k);
    }


    //
    // 计算 maxP
    //
    for (int i = 1; i < ave.size(); i++) {
        double t = (ave[i]-ave[i-1])/ave[i-1];
        if (t > maxP) {
            maxP = t;
        }
    }
    printf("%.2lf%%", maxP * 100);

    return maxP;
}

