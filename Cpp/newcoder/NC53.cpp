/*
 * 给定一个链表，删除链表的倒数第 nn 个节点并返回链表的头指针
例如，
给出的链表为: 1\to 2\to 3\to 4\to 51→2→3→4→5, n= 2n=2.
删除了链表的倒数第 nn 个节点之后,链表变为1\to 2\to 3\to 51→2→3→5.

备注：
题目保证 nn 一定是有效的
请给出请给出时间复杂度为\ O(n) O(n) 的算法
 */

/**
 * 运行时间：3ms
超过30.31%用C++提交的代码
占用内存：396KB
超过52.48%用C++提交的代码
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // write code here
    ListNode* pFast = head;
    ListNode* pSlow = head;
    ListNode* pDelete;
    for (int i = 0; i < n; i++) {
        pFast = pFast->next;
        // pFast 为 NULL 说明删除目标为第一个节点
        if (pFast == NULL) {
            pDelete = head;
            head = head->next;
            delete pDelete;
            return head;
        }
    }
    while (pFast->next != NULL) {
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    pDelete = pSlow->next;
    // 删除目标为最后一个时
    if (n == 1) {
        pSlow->next = NULL;
    } else {
        pSlow->next = pDelete->next;
    }
    delete pDelete;

    return head;
}