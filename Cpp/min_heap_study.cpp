/**
 *  堆的使用
 */
#include <iostream>
#include <queue>

using namespace std;

/**
 * 优先队列实现小顶堆
 */
void test_0() {
    cout << "min heap" << endl;
    // priority_queue 来自 queue
    // Container 必须是用数组实现的容器，比如 vector,deque 等等，但不能用 list。
    // 为什么要 container 呢？难道二叉堆是用数组实现的？
    // 第二个参数定义基础序列/容器的类型
    // 第二、三个参数好理解，第 1 个参数如何理解？C++里面，给出容器类型时必须要指定容器里元素类型
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    test_0();

    return 0;
}