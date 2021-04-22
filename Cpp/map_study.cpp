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
 * map 必须得有键值对，不能只有一个键
 */
void test_2() {
//    map<int> mymap;
//    mymap[29];
//    cout << mymap.at(29) << endl;
}

int main() {

    test_1();

    return 0;
}