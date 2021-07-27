/**
 * 哈希表 = key-value 键值对 == 字典
 */
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

/**
 * 哈希表的创建
 */
void test_0() {
    unordered_map<string, string> map1;
    map1["name"] = "unknown";
    map1["age"] = "18";
    cout << map1["name"] << endl;
    cout << map1["age"] << endl;
}

/**
 * 判断键值对是否存在
 *
 * 还可以用 count 函数，存在返回 1，不存在返回 0
 */
void test_1() {
    unordered_map<string, string> map1;
    map1["name"] = "unknown";

    // 查找时间复杂度为 O(1)
    if (map1.find("name") != map1.end()) {
        cout << map1["name"] << endl;
    }
    if (map1.find("age") != map1.end()) {
        cout << map1["age"] << endl;
    } else {
        cout << "can't find key: age" << endl;
    }
}


/**
 * 哈希表遍历
 */
void test_2() {
    unordered_map<string, string> map1;
    map1["name"] = "Tom";
    map1["gender"] = "male";

    // 使用 pair 来表示 hash 表中的一个元素，像 Python 中的元组
    for (pair<string, string> s : map1) {
        cout << s.first << ":" << s.second << endl;
    }
}

/**
 * 当 value 为 int 时，其初始值为 0
 */
void test_3() {
    unordered_map<char, int> target;
    string s("hello");
    for(auto &c:s) {
        cout << target[c] << endl;
        target[c]++;
    }

    for (auto it = target.begin(); it != target.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}


int main() {
    test_3();

    return 0;
}
