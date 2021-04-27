

/*
 运行时间：3ms
超过31.37%用C++提交的代码
占用内存：376KB
超过75.90%用C++提交的代码
 */
class Solution {
public:
    bool isAsc(ListNode *pHead) {
        if (pHead == NULL)
            return false;
        if (pHead->next == NULL)
            return true;
        ListNode *p1 = pHead;
        ListNode *p2 = p1->next;
        while (p2 != NULL) {
            if (p2->val > p1->val)
                return true;
            p1 = p2;
            p2 = p2->next;
        }


        return true;
    }

    ListNode* reverseList(ListNode *pHead) {
        if (pHead == NULL)
            return NULL;
        if (pHead->next == NULL)
            return pHead;
        ListNode *p1, *p2, *p3, *newHead;
        p1 = pHead;
        p2 = p1->next;
        p3 = p2->next;
        p1->next = NULL;
        while (p3 != NULL) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        newHead = p2;
        return newHead;
    }
    /**
     *
     * @param l1 ListNode类
     * @param l2 ListNode类
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        if (!isAsc(l1)) {
            l1 = reverseList(l1);
        }
        if (!isAsc(l2)) {
            l2 = reverseList(l2);
        }
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *pHead = NULL;
        ListNode *p;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                if (pHead == NULL) {
                    p = pHead = p1;
                } else {
                    p->next = p1;
                    p = p->next;
                }
                p1 = p1->next;
            } else {
                if (pHead == NULL) {
                    p = pHead = p2;
                } else {
                    p->next = p2;
                    p = p->next;
                }
                p2 = p2->next;
            }
        }
        while (p1 != NULL) {
            if (pHead == NULL) {
                return p1;
            }
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            if (pHead == NULL) {
                return p2;
            }
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
        p->next = NULL;

        return pHead;
    }
};