/**
 * 哈希表 = key-value 键值对 == 字典
 *
 * 标准 std 中只有 map, 没有提供 hash map
 * gnu c++ 提供了 hash_map，是一个 hash map 的实现，查找和添加复杂度均为 O(1)。
 *
 * c++ tr1(C++ Technical Report 1) 作为标准的扩展，实现了 hash map，
 * 提供了和 stl 兼容一致的 api，称为 unordered_map，在头文件 <tr1/unordered_map> 中。
 * 另外 c++ tr1 还提供了正则表达式、智能指针、hash table、随机数生成器的功能。
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

int main() {
    test_2();

    return 0;
}
