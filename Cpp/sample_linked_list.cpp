/*
 * list 的简单使用
 */
#include <list>
#include <iostream>
using namespace std;

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6};

    // 初始化一个列表
    list<int> lst(a, a+6);

    for (int n : lst) {
        printf("%d\n", n);
    }


    return 0;
}