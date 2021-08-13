/**
 * JZ16 合并两个排序的链表
 *
 * 描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

 示例1
输入：{1,3,5},{2,4,6}
返回值：{1,2,3,4,5,6}
 */

/**
 * 思路：挨个比较，但要注意一个链表中相同值的处理
 *
    {1,2,2,3,4,5},{1,2,2,3,4,5}

    运行时间：4ms
超过7.82% 用C++提交的代码
占用内存：616KB
超过15.98%用C++提交的代码
    */
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL && pHead2 == NULL) {
        return NULL;
    }
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }

    ListNode *newHead = NULL;
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
    while (p1 && p2) {
        ListNode *p3;

        //
        // p1 小于 p2
        //
        if (p1->val <= p2->val) {
            if (newHead == NULL) {
                newHead = p1;
            }
            // p1 后面还比 p2 小
            if (p1->next && p1->next->val <= p2->val) {
                p1 = p1->next;
            } else {
                p3 = p1->next;
                p1->next = p2;
                p1 = p3;
            }
            // p2 小于 p1
        } else if (p1->val > p2->val) {
            if (newHead == NULL) {
                newHead = p2;
            }
            // p2 后面还比 p1 小
            if (p2->next && p2->next->val < p1->val) {
                p2 = p2->next;
            } else {
                p3 = p2->next;
                p2->next = p1;
                p2 = p3;
            }
        }
    }
    return newHead;
}