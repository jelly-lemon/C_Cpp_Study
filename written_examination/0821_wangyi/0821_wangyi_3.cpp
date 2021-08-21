#include <iostream>
#include <vector>

using namespace std;


/**
 * 纸张分配问题
 * AC 30%
 *
 小孩围成圈坐，每个小朋友至少有发一张纸，年龄大的小孩必须比旁边年龄小的多，
 年龄相同时可以相同。

 求最少发的纸张数量。
 */
int main() {
    vector<int> vec;

    // 输入数组
    int minAgeP = -1;
    while (1) {
        int n;
        cin >> n;
        vec.push_back(n);

        if (minAgeP == -1) {
            minAgeP = 0;
        } else {
            if (n < vec[minAgeP]) {
                minAgeP = vec.size() - 1;
            }
        }

        char c = getchar();
        if (c == '\n' ) {
            break;
        }
    }

    vector<int> childPapper(vec.size());
    int p = minAgeP;
    int len = vec.size();
    for (int i = 0; i < len; i++) {
        if (p == minAgeP) {
            childPapper[p] = 1;
            p++;
            p = p % len;
        } else {
            int frontP = p-1 >= 0 ? p-1 : len-1;
            if (vec[p] > vec[frontP]) {
                childPapper[p] = childPapper[frontP] + 1;
            } else if (vec[p] == vec[frontP]){
                childPapper[p] = childPapper[frontP];
            } else {
                childPapper[p] = childPapper[frontP] - 1;
            }
            // 最后一个小孩
            if (i+1 == len && vec[p] > vec[minAgeP]) {
                childPapper[p]++;
            }
        }
    }

    int count = 0;
    for (auto &n:childPapper) {
        count += n;
    }

    cout << count << endl;

    return 0;
}