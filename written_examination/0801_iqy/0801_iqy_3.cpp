/**
 * [1,2,0,0,2,1]
 *
 * 避险水库泄洪
 */


#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {
    vector<int> ans;

    //
    // 输入数组
    //
    vector<int> arr;
    int a, k;
    char c;
    while (cin >> c) {
        if (c == ']') {
            break;
        } else {
            cin >> a;
            arr.push_back(a);
            ans.push_back(-1);
        }
    }


    //
    // 抽水
    //
    set<int> fullPosition;
    for (int i = 0; i < arr.size(); i++) {
        // 下雨
        if (arr[i] > 0) {
            ans[i] = -1;

            // 空 -> 下雨装满
            if(fullPosition.find(arr[i]) == fullPosition.end()) {
                fullPosition.insert(arr[i]);
            } else {
                // 已装满 -> 找晴天抽空
                int j;
                for (j = i-1; j >= 0; j--) {
                    if (arr[j] == 0 && ans[j] == -1) {
                        ans[j] = arr[i];
                        fullPosition.erase(arr[i]);
                        break;
                    }
                }
                // 没法抽空
                if (j == -1) {
                    ans.clear();
                    break;
                }
            }
        }
    }

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i +1 == ans.size()) {
            cout << ans[i];
        } else {
            cout << ans[i] << ",";
        }
    }
    cout << "]" << endl;

    return 0;

}

