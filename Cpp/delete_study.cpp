/**
 * 删除结构体中的数组
 */

#include <cstring>
#include <iostream>
using namespace std;

struct Student {
    int mAge;
    char name[1024000];
};

/**
 * 使用 new 创建，delete 删除结构体
 *
 * 【注意】申请的空间可能不会被立即释放，内核有自己的管理方式。
 */
void test_0() {
    A *p = new A;

    delete p;
    p = NULL;
    cout << "test_0" << endl;
}

/**
 * 栈空间申请对象
 */
void test_1() {
    A a = {};

    cout << "test_1" << endl;
}

/**
 * 直接申请数组
 */
void test_2() {
    int *a = new int[1024000];
    a[0] = 1;

    delete[] a;

    printf("ok\n");
}

int main() {
    test_0();
    test_0();
    test_0();
    test_0();

    return 0;
}