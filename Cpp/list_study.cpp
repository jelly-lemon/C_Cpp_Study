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

/**
 * 取 list 首元素
 */
void test_2() {
    list<string> msgList;
    string s = msgList.front();
    printf("%s\n", s.c_str());
}


void test_3() {
    list<int> myList;
    int size = myList.size();
    printf("size=%d\n", size);
}

int main() {
    test_3();

    return 0;
}