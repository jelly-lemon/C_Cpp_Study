/*
 判断给定的链表中是否有环。如果有环则返回true，否则返回false。
你能给出空间复杂度O(1)的解法么？
 */

/*
 运行时间：11ms
超过39.59%用C++提交的代码
占用内存：980KB
超过95.35%用C++提交的代码
 */
bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;
    ListNode* pSlow = head;
    ListNode* pFast = head;
    while(pFast != NULL) {
        if (pFast->next == NULL)
            return false;
        else {
            if (pFast->next->next == NULL)
                return false;
            else {
                pFast = pFast->next->next;
                pSlow = pSlow->next;
                if (pFast == pSlow || pFast->next == pSlow)
                    return true;
            }
        }

    }
    return false;
}