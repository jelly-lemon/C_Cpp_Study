#include <iostream>
#include <vector>

using namespace std;


/**
 * 动态创建二维数组
 */
void test_0() {
    int **a = new int*[3];  // 创建一个二维指针数组，长度为 3

    // 创建 3 个一维数组，并把一维数组首地址保存在指针数组当中
    for (int i = 0; i < 3; i++) {
        a[i] = new int[5];
    }

    delete[] a; // 释放申请的空间
}

/**
 * 使用 vector 创建二维数组
 */
void test_1() {
    int n = 10, m = 2;
    vector<vector<int>> a(n);   // 创建一个二维数组，有 10 行
    for (int i = 0; i < n; i++) {
        a[i].resize(m);     // 每个一维数组有两列
    }
}

int main() {
    test_0();

    return 0;
}