/**
 * 正则表达式
 */

#include <iostream>
#include <regex>
#include <cstdio>
using namespace std;

/**
 * 匹配是否存在
 */
void test_0() {
    string str = "hhh123";
    regex r("[a-z0-9]+");

    bool flag = regex_match(str, r);
    if (flag) {
        cout << "yes" << endl;
    }
}

/**
 * 查找字串
 */
void test_1() {
    string str("abc, hhh123, de");   // 字符串
    regex e("[a-z0-9]+");   // 正则表达式
    smatch m;   // 保存匹配结果
    // 【易错点】regex_match 和 regex_search 功能相同，但 match 要求完全匹配，search 字串匹配即可
    bool found = regex_search(str, m, e);
    if (found) {
        cout << "m.size()=" << m.size() << endl;
        for (int i = 0; i < m.size(); i++) {
            printf("m.str(%d)=%s\n", i, m.str(i).c_str());
        }
        cout << "m.prefix().str(): " << m.prefix().str() << endl;
        cout << "m.suffix().str(): " << m.suffix().str() << endl;
    } else {
        cout << "not found" << endl;
    }
}


int main() {
    test_1();

    return 0;
}

