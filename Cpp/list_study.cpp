/*
 * list 的简单使用
 */
#include <list>
#include <cstdio>
using namespace std;

void test_1() {
    int a[6] = {1, 2, 3, 4, 5, 6};

    // 初始化一个列表
    list<int> lst(a, a+6);
    for (int n : lst) {
        printf("%d\n", n);
    }
}

int main() {


    return 0;
}