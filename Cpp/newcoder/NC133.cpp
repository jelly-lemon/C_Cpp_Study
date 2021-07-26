/**
     * 运行时间：23ms
超过63.52% 用C++提交的代码
占用内存：5052KB
超过18.76%用C++提交的代码
     * @param head ListNode类
     * @return ListNode类
     */
ListNode *oddEvenList(ListNode *head) {
    //
    // 空节点、一个节点、两个节点、三个节点，都不需要操作
    //
    if (head == NULL || head->next == NULL || head->next->next == NULL || head->next->next->next == NULL) {
        return head;
    }

    ListNode *p1 = head;
    ListNode *p2 = p1->next;
    ListNode *head2 = p2;   // 偶链表头节点
    ListNode *pTail = p1;   // 奇链表尾节点
    //
    // 奇偶分家
    //
    while (p1) {
        if (p2 == NULL) {
            break;
        }
        p1->next = p2->next;
        p1 = p2->next;
        if (p1 == NULL) {
            break;
        }
        pTail = p1;
        p2->next = p1->next;
        p2 = p1->next;
    }
    // 善后
    if (p2 != NULL) {
        p2->next = NULL;
    }
    // 奇偶合并
    pTail->next = head2;

    return head;
}