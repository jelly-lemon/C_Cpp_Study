/**
 * 最小的旋转链表
 *
 * 旋转链表，像字符串那样比较，求最小的旋转链表
 */

struct ListNode {
    int val;
    struct ListNode *next;
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param S ListNode类 val表示权值，next指向下一个元素
     * @return ListNode类
     */
    ListNode* solve(ListNode* S) {
        // write code here
        int len = getLen(S);
        int i;
        if (len == 1){
            return S;
        }

        // 变成环
        ListNode *pOld, *pNew, *pMin, *p;
        while (p->next) {
            p = p->next;
        }
        p->next = S;

        // 找最小
        pMin = S;
        for (i = 0; i < len-1; i++) {
            pNew = moveList(pMin);
            pMin = getMin(pMin, pNew, len);
        }

        return pNew;
    }

    int getLen(ListNode* pHead) {
        ListNode* p = pHead;
        int count = 0;
        while(p) {
            count++;
            p = p->next;
        }
        return count;
    }
    ListNode* moveList(ListNode* S) {
        ListNode* pHead = S;
        ListNode* p = pHead;
        while(p->next->next) {
            p = p->next;
        }
        p->next->next = pHead;
        pHead = p->next;
        p->next = NULL;
        return pHead;
    }

    ListNode* getMin(ListNode* pOld, ListNode* pNew, int len) {
        ListNode* p1 = pOld;
        ListNode* p2 = pNew;
        for (int i = 0; i < len; i++) {
            if (p2->val < p1->val) {
                return pNew;
            } else if (p2->val > p1->val){
                return pOld;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return pNew;
    }
};