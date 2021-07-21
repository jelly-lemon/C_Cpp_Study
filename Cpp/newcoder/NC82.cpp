/*
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
 * 那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 * {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}，
 * {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 * {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
窗口大于数组长度的时候，返回空

 输入：
 [2,3,4,2,6,2,5,1],3
 返回值：
 [4,4,6,6,6,5]
 */

void popFirst(priority_queue<int, vector<int>, less<int> > &maxHeap, int &first) {
    list<int> l_num;

    while (maxHeap.top() != first) {
        l_num.push_back(maxHeap.top());
        maxHeap.pop();
    }
    maxHeap.pop();    // 弹出第一元素

    for (auto k:l_num) {
        maxHeap.push(k);
    }

}

/**
 * 思路 1：构建大顶堆，新元素入堆前，先删除堆中最先入堆的元素
 * 具体做法为：top 挨个比较，如果不是，就一直堆顶元素出堆，并保存到一个数组中，
 * 第一元素出堆后，再把之前的元素回堆
 *
 * 运行时间：2ms
超过76.42% 用C++提交的代码
占用内存：492KB
超过35.04%用C++提交的代码
 */
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    vector<int> v_max;
    if (size == 0 or size > num.size())
        return v_max;

    priority_queue<int, vector<int>, less<int> > maxHeap;

    // 第一个窗口
    for (int i = 0; i < size; i++)
        maxHeap.push(num[i]);
    v_max.push_back(maxHeap.top());

    // 后面窗口
    for (int i = size; i < num.size(); i++) {
        int first = num[i-size];
        popFirst(maxHeap, first);
        maxHeap.push(num[i]);
        v_max.push_back(maxHeap.top());
    }

    return v_max;
}

/**
 * 思路 2：i_new, i_max, i_first，分情况讨论
 * 分三种情况
 * i_new > i_max
 * i_new == i_max
 * i_new < i_max：这种情况最复杂，需要 i_max = findMax(i_first, i_new)
 */
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {

}



