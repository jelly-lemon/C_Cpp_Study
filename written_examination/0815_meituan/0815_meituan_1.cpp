/**
 * 序列检查
 *
 * 小美给小团一个n个数字构成的数字序列，问小团能不能经过重新排列后形成1到n的排列。

举例：

小美给小团[2, 1, 3]，则可以经过重新排列后构成[1, 2, 3]，这是可行的。

小美给小团[4, 4, 1, 3]，则无法经过重新排列后构成[1, 2, 3, 4]，这是不可行的。

为了防止小团靠运气碰对答案，小美会进行多组询问。

 输入描述
第一行是一个数T，表示有T组数据。

对于每组数据：

第一行一个数字n表示小美给出的序列由n个数字构成。

接下来一行n个空格隔开的正整数。

输出描述
对于每组数据，如果可以重新排列后得到1到n的排列，回答一行Yes，如果不可以，回答No

请注意大小写。


样例输入
2
3
2 1 3
4
4 4 1 3
样例输出
Yes
No

提示
数据范围和说明

对于40%的数据，数组组数T <= 10,每组数据的序列长度n <= 100

对于100%的数据，数组组数T <= 1,000,每组数据的序列长度n <= 1,000

注意：不保证给出的数字序列都是在1到n的范围内的，但保证都是int范围下的自然数。
 */
#include<iostream>
#include<unordered_map>
using namespace std;

void isOK(int *p, int len) {
    unordered_map<int, int> hashMap;
    for (int i = 0; i < len; i++) {
        if (hashMap.find(p[i]) != hashMap.end()) {
            cout << "No" << endl;
            return;
        } else {
            hashMap[p[i]] = p[i];
        }
        if (p[i] < 1 || p[i] > len) {
            cout << "No" << endl;
            return;
        }

    }

    cout << "Yes" << endl;
}

int main() {
    int T;
    cin >> T;
    int n;
    for (int i = 0; i < T; i++) {
        cin >> n;
        int *p = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> p[j];
        }
        isOK(p, n);
        delete []p;
    }


    return 0;
}