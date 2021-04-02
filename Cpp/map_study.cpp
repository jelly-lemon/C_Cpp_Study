#include <map>
#include <iostream>
using namespace std;

/**
 * map 的插入与获取
 */
void test_1() {
    map<string, string> header;
    header["url"] = "http://localhost:8080";
    cout << header.at("url") << endl;
}

int main() {

    test_1();

    return 0;
}