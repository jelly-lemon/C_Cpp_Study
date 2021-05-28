/**
 *  堆
 *
 * 优先队列与堆的关系？优先队列就是一个堆，堆中节点的值就是优先级
 *
 * 具体的数据结构：数组、链表
 * 抽象的数据结构：二叉树、队列、栈、优先队列、堆等
 *
 * 堆：是一种抽象的数据结构，我们在插入或删除元素后堆将自动调整结构以维持有序，可用二叉树实现。
 * 优先队列：是一种抽象的数据结构，在队列的基础上定义了元素的优先级，可用堆实现。
 * 堆排序：使用数据结构堆实现的排序算法。
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
    // Container 必须是用数组实现的容器，比如 vector、deque 等等，但不能用 list。
    // 为什么要 container 呢？难道二叉堆是用数组实现的？
    // 第二个参数定义基础序列/容器的类型
    // 第二、三个参数好理解，第 1 个参数如何理解？C++里面，给出容器类型时必须要指定容器里元素类型
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);

    }
    // 取出堆顶元素
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

/**
 * 大顶堆
 */
void test_1() {
    // 默认比较函数就是 less，这个比较函数刚好和顶元素相反，注意一下
    priority_queue<int, vector<int>, less<int> > q;
    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }

    // 取出堆顶元素
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

/**
 * 设置堆的容量
 */
void test_2() {

}

void test_3() {
    priority_queue<int, vector<int>, less<int> > maxHeap;

}

int main() {
    test_1();

    return 0;
}