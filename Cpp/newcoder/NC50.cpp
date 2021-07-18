#include <iostream>

using namespace std;
/**
 * 将给出的链表中的节点每\ k k 个一组翻转，返回翻转后的链表
如果链表中的节点数不是\ k k 的倍数，将最后剩下的节点保持原样
你不能更改节点中的值，只能更改节点本身。
要求空间复杂度 \ O(1) O(1)
例如：
给定的链表是1\to2\to3\to4\to51→2→3→4→5
对于 \ k = 2 k=2, 你应该返回 2\to 1\to 4\to 3\to 52→1→4→3→5
对于 \ k = 3 k=3, 你应该返回 3\to2 \to1 \to 4\to 53→2→1→4→5
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

ListNode* reverseCore(ListNode* pStart, ListNode* &pNextStart, int k) {
    if (pStart == NULL) {
        return NULL;
    }
    if (k <= 1) {
        return pStart;
    }

    //
    // 判断长度是否有 k
    //
    int len = 0;
    ListNode* p = pStart;
    while (p) {
        p = p->next;
        len++;
        if (len == k) {
            pNextStart = p;
            break;
        }
    }
    if (len < k) {
        pNextStart = NULL;
        return pStart;
    }

    //
    // 反转链表
    //
    ListNode *p1, *p2, *p3;
    p1 = pStart;
    p2 = p1->next;
    p3 = p2->next;
    for (int i = 0; i < k-1; i++) {
        if (i == 0) {
            p1->next = NULL;
        }
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if (p3 == NULL) {
            break;
        }
    }
    return p1;
}

/**
*
*/
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) {
        return head;
    }
    if (k <= 1) {
        return head;
    }

    ListNode *pReversedHead = NULL;
    ListNode *pReversedPreviousTail = NULL;
    ListNode *pStart = head;
    ListNode *pNextStart = NULL;
    int count = 0;
    while (1) {
        pReversedHead = reverseCore(pStart, pNextStart, k);
        //intf("pStart:%d\n", pStart->val);
        //intf("pReversedHead:%d\n", pReversedHead->val);
        if (pReversedHead != pStart) {
            if (count == 0) {
                head = pReversedHead;
                pReversedPreviousTail = pStart;
            } else {
                pReversedPreviousTail->next = pReversedHead;
                pReversedPreviousTail = pStart;
            }
            //intf("pReversedPreviousTail:%d\n", pReversedPreviousTail->val);
            if (pNextStart != NULL) {
                pStart = pNextStart;
                count++;
            } else {
                if (pReversedPreviousTail != pStart) {
                    pReversedPreviousTail->next = pStart;
                }
                break;
            }
        } else {
            if (pReversedPreviousTail != NULL) {
                pReversedPreviousTail->next = pReversedHead;
            }
            break;
        }
    }

    return head;
}

int main() {

    return 0;
}