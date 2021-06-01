/*
 * 实现一个特殊功能的栈，
 * 在实现栈的基本功能的基础上，
 * 再实现返回栈中最小元素的操作。
 * 输入：[[1,3],[1,2],[1,1],[3],[2],[3]]
 * 返回值：[1,2]
 */

/**
 * 思路 1：用一个辅助栈来存储最小值
 *
 * 运行时间：15ms
超过49.83% 用C++提交的代码
占用内存：1312KB
超过61.67%用C++提交的代码
 */

vector<int> getMinStack(vector<vector<int> >& op) {
    // write code here
    stack<int> minStack;
    vector<int> result;
    int min = 1000001;
    for (auto v : op) {
        if (v[0] == 1) {
            if (v[1] < min)
                min = v[1];
            minStack.push(min);
        } else if (v[0] == 2) {
            int t = minStack.top();
            minStack.pop();
            // 【易错点】容易忘记判断 minStack 此时是否为空
            if (minStack.size() == 0) {
                min = 1000001;
            } else if (t == min) {
                min = minStack.top();
            }

        } else if  (v[0] == 3) {
            result.push_back(minStack.top());
        }
    }
    return result;
}