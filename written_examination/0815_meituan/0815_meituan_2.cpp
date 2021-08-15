/**
小美的回文串构建
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小美现在有一个字符串，小美现在想知道能不能通过在字符串的尾端增加若干字符使得整个字符串变成一个回文串。
回文串的定义：若一个字符串，对他正序遍历和倒序遍历得到的结果是完全一致的，就称它是一个回文串。
 例如 abcba 就是一个回文串，因为无论正序还是倒序都是一样的。
对于字符串 abaaca，显然在该字符串末尾继续补上三个字符 aba 就可以构成 abaacaaba，就可以把原字符串变成回文串。
 换句话说，最少补上三个字符。
你的任务就是找到使得原来的字符串变成回文串所需要的最少字符数量。
* 本题数据保证没有空串，因此不考虑空串是否为回文串。
保证输入的字符串仅包含小写字母。


输入描述
一行一个字符串，代表小美交给你的字符串。

输出描述
一行一个整数，表示将小美给出的字符串变成回文字符串所需要添补的最少字符数量。


样例输入
abaaca
样例输出
3

提示
输入样例2

aba

输出样例2

0

数据范围和说明

对于40%的数据，字符串长度小于等于10

对于60%的数据，字符串长度小于等于1,000

对于100%的数据，字符串长度小于等于1,000,000
 */

#include <iostream>
using namespace std;

/**
 * 是否回文串
 */
bool isOK(string &s) {
    int len = s.length();
    for (int i = 0; i < len/2; i++) {
        // 【易错点】 易误写成 s[len-i]
        if (s[i] != s[len-1-i]) {
            return false;
        }
    }

    return true;
}

/**
 * 思路 1：暴力法
 *
 * 所有测试数据正确率为 73%！超时
 */
int getLeastNumber(string &s) {
    if (isOK(s)) {
        return 0;
    }

    // 最大补充长度：len-1
    for (int minLen = 1; minLen < s.length(); minLen++) {
        string subStr = s.substr(minLen);
        if (isOK(subStr)) {
            return minLen;
        }
    }

    return -1;
}

int main() {
    string s1;

    cin >> s1;

    int n = getLeastNumber(s1);

    cout << n << endl;
    return 0;
}