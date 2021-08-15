/**
找出包含二十六个小写字母的最短区间长度

 问好是万能牌，想变啥就变啥

 "abcdefghijklmnopqrstuvwwwwxyz"
 29

 "abcdefghijklmnopqrstuvw???xyz"
 26

 *
 */

#include <iostream>
#include <stack>

using namespace std;

bool isInclude(string &s) {
    int result[26] = {0};
    int count = 0;
    for (auto &c:s) {
        if ('a' <= c && c <= 'z') {
            result[c-'a'] = 1;
        } else {
            count++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (result[i] != 1) {
            count--;
        }
    }

    if (count >= 0) {
        return true;
    } else {
        return false;
    }
}

/**
思路 1：滑动窗口

 通过 70%，其余超时

 * "abcdefghijklmnopqrstuvw???xyz"
 */
int findInterval(string str) {
    // write code here
    int len = str.size();
    int minLen =-1;
    int start = 0, subLen = 26;
    while (start+subLen <= len) {
        string s = str.substr(start, subLen);
        // 起点前增：已包含
        while (isInclude(s)) {
            if (minLen != -1) {
                if (minLen > subLen) {
                    minLen = subLen;
                }
            } else {
                minLen = subLen;
            }

            if (subLen - 1 >= 26) {
                start++;
                subLen--;
                s = str.substr(start, subLen);
            } else {
                break;
            }
        }

        // 窗口扩大：未包含
        subLen++;
    }


    return minLen;
}

int main() {
    int minLen = findInterval("abcdefghijklmnopqrstuvw???xyz");
    cout << minLen << endl;

    return 0;
}