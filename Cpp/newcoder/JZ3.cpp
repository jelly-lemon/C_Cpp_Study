/**
 * 输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。

如输入{1,2,3}的链表如下图:

返回一个数组为[3,2,1]

0 <= 链表长度 <= 1000

示例1
输入：{1,2,3}

返回值：[3,2,1]
 */

/**
    运行时间：3ms
超过31.65% 用C++提交的代码
占用内存：524KB
超过59.86%用C++提交的代码
*/
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> myVec;
    stack<int> myStack;
    if (head == NULL) {
        return myVec;
    }

    ListNode *p = head;
    while(p) {
        myStack.push(p->val);
        p = p->next;
    }

    while (!myStack.empty()) {
        int val = myStack.top();
        myStack.pop();
        myVec.push_back(val);
    }

    return myVec;
}