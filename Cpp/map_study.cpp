#include <map>
#include <iostream>
using namespace std;

/**
 * map 的插入与获取
 */
void test_1() {
    map<string, string> header;
    header["url"] = "http://localhost:8080";    // 插入
    cout << header.at("url") << endl;   // 获取

    // 判断是否存在
    if (header.find("hello") == header.end()) {
        cout << "key:hello not exists" << endl;
    }
}


/**
 * 通过迭代器获取 value
 */
void test_2() {
    map<string, int> m1;
    m1["name"] = 3;

    printf("%d\n", m1.begin()->second);
}

void test_3() {

}

int main() {

    test_2();

    return 0;
}