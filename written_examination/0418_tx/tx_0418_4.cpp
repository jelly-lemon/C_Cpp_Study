/**
 * 相等字符串
 *
 * 字符串 a 和 b
 * 如果是奇数串，普通相等
 * 如果是偶数串，比较 a1 == b1 && a2 == b2 或者 a1 == b2 && a2 == b1，递归判断，满足条件就算相等字符串
 */

#include<iostream>
#include<vector>

using namespace std;

int compare(string s1, string s2) {
//    cout << s1 << endl;
//    cout << s2 << endl;
    int len = s1.length();
    if (len % 2 == 1) {
        if (s1 == s2) {
//            cout << "equal" << endl;
            return 0;
        } else {
            return 1;
        }
    } else {
        if ((compare(s1.substr(0, len / 2), s2.substr(0, len / 2)) == 0 &&
             compare(s1.substr(len / 2), s2.substr(len / 2)) == 0) ||
            (compare(s1.substr(0, len / 2), s2.substr(len / 2)) == 0 &&
             compare(s1.substr(len / 2), s2.substr(0, len / 2)) == 0)) {
            return 0;
        } else {
            return 1;
        }
    }
}


int main() {
    int t;

    cin >> t;
    vector<string> sVec(2 * t);
    for (int i = 0; i < 2 * t; i++) {
        string s;
        cin >> s;
        sVec[i] = s;
    }

    // 比较
    for (int i = 0; i < 2 * t; i += 2) {
        if (compare(sVec[i], sVec[i + 1]) == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}