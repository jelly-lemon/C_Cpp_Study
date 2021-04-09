/*
 * list 的简单使用
 */
#include <list>
#include <cstdio>
#include <string>

using namespace std;

/**
 * 遍历 list
 */
void test_1() {
    int a[6] = {1, 2, 3, 4, 5, 6};

    // 初始化一个列表
    list<int> lst(a, a+6);
    for (int n : lst) {
        printf("%d\n", n);
    }
}

void test_2() {
    list<string> msgList;
    string s = msgList.front();
    printf("%s\n", s.c_str());
}


int main() {
    test_2();


    return 0;
}