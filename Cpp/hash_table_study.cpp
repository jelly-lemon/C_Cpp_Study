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
 */
void test_1() {
    unordered_map<string, string> map1;
    map1["name"] = "unknown";

    if (map1.find("name") != map1.end()) {
        cout << map1["name"] << endl;
    }
    if (map1.find("age") != map1.end()) {
        cout << map1["age"] << endl;
    } else {
        cout << "can't find key: age" << endl;
    }
}

int main() {
    test_1();



    return 0;
}
