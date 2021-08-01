/**
 * aaa,bbb,ccc
 *
 * 多线程翻译
 */


#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <pthread.h>
#include <algorithm>
using namespace std;

void* translateAll(void *args) {
    vector<string> &lines = *(vector<string>*)args;
    for (int i = 0; i < lines.size(); i++) {
        string &l = lines[i];
        for (auto &c:l) {
            if ('a' <= c && c <= 'z') {
                c = c-'a'+'A';
            }
        }

    }
    return NULL;
}


int main() {
    //
    // 输入数组
    //
    vector<string> lines;
    string inputStr;
    cin >> inputStr;
    string s;
    for (auto &c:inputStr) {
        if (c != ',') {
            s += c;
        } else {
            lines.push_back(s);
            s = "";
        }
    }
    lines.push_back(s);

    pthread_t t1;
    pthread_create(&t1, NULL, translateAll, (void*)&lines);
    pthread_join(t1, NULL);

    for (int i = 0; i < lines.size(); i++) {
        string &l = lines[i];
        if (i + 1 != lines.size()) {
            cout << l << ",";
        } else {
            cout << l << endl;
        }
    }

    return 0;
}

