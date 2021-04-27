
/*
 运行时间：3ms
超过29.44%用C++提交的代码
占用内存：484KB
超过55.67%用C++提交的代码
 */
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
    while(p1 != NULL) {
        p2 = pHead2;
        while (p2 != NULL) {
            if (p1->val == p2->val)
                return  p1;
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
    return NULL;
}