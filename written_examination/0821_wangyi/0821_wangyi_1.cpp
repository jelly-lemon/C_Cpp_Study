/**
 *
数组中两个元素和小于 M 的组数
 * 输入一行数组
 * 再输入一个目标值 M
 *
 * 找出两个数之和小于 M 的对数
 */

#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> vec;

    // 输入数组
    while (1) {
        string s;
        char c = getchar();
        while (c != ' ' && c != '\n') {
            s += c;
            c = getchar();
        }
        int n = stoi(s);
        vec.push_back(n);
        if (c == '\n') {
            break;
        }
    }


    // 输入 M
    int M;
    cin >> M;


    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        // 【易错点】即使某一个正数比 M 大，但是还有可能加一个负数啊
        for (int j = i+1; j < vec.size(); j++) {
            if (vec[i] + vec[j] <= M) {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}