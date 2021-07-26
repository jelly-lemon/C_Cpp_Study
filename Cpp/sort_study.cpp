#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
 * 自定义比较函数
 */
struct cmp_greater {
    bool operator()(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        string s3 = s1 + s2;
        string s4 = s2 + s1;

        return s3 > s4;
    }
};

/**
 * 字符串默认升序
 */
void test_0() {
    vector<string> vec;
    vec.push_back("abc");
    vec.push_back("hello");
    vec.push_back("nihao");
    vec.push_back("good");

    // 默认升序
    sort(vec.begin(), vec.end());
    for (string &s:vec) {
        cout << s << " ";
    }
    cout << endl;

    // 降序排序
    greater<string> g;
    sort(vec.begin(), vec.end(), g);
    for (string &s:vec) {
        cout << s << " ";
    }
    cout << endl;
}

/**
 * 使用自定义比较函数
 */
void test_1() {
    vector<int> vec;
    vec.push_back(763);
    vec.push_back(51);
    vec.push_back(9);
    vec.push_back(324);
    vec.push_back(10);
    vec.push_back(1);


    cmp_greater g;
    sort(vec.begin(), vec.end(), g);
    for (auto &s:vec) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    test_1();

    return 0;
}