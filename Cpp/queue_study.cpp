/**
 * 队列学习
 */
#include <iostream>
#include <queue>
using namespace std;

/**
 * 入队和出队
 */
void test_0() {
    queue<int> q1;
    q1.push(1);

    // 队首元素出队，没有返回值，仅仅是删除队首元素
    q1.pop();
}

int main() {


    test_0();
    return 0;
}