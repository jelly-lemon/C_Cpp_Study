#include <iostream>

using namespace std;
/**
 *
 * NC50 链表中的节点每k个一组翻转
 *
 * 将给出的链表中的节点每\ k k 个一组翻转，返回翻转后的链表
如果链表中的节点数不是\ k k 的倍数，将最后剩下的节点保持原样
你不能更改节点中的值，只能更改节点本身。
要求空间复杂度 \ O(1) O(1)
例如：
给定的链表是 1→2→3→4→5
对于 k=2, 你应该返回 2→1→4→3→5
对于 k=3, 你应该返回 3→2→1→4→5


 */

struct ListNode {
    int val;
    struct ListNode *next;
};

ListNode *reverseCore(ListNode *pStart, ListNode *&pNextStart, int k) {
    pNextStart = NULL;
    if (pStart == NULL) {
        return NULL;
    }
    if (pStart->next == NULL) {
        return pStart;
    }
    if (k <= 1) {
        return pStart;
    }

    //
    // 判断长度是否有 k
    //
    int len = 0;
    ListNode *p = pStart;
    while (p) {
        p = p->next;
        len++;
        if (len == k) {
            break;
        }
    }
    if (len < k) {
        return pStart;
    }

    //
    // 反转链表
    // k 代表链表长度，也代表翻转次数
    //
    ListNode *p1, *p2, *p3;
    p1 = NULL;
    p2 = pStart;
    p3 = p2->next;
    for (int i = 0; i < k - 1; i++) {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    pNextStart = p2->next;
    p2->next = p1;

    //
    // 返回新链首元素
    //
    return p2;
}

/**
* 按段翻转链表
 *
 * 运行时间：3ms
超过89.42% 用C++提交的代码
占用内存：440KB
超过91.83%用C++提交的代码
*/
ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        return head;
    }
    if (k <= 1) {
        return head;
    }

    ListNode *pReversedHead = NULL;
    ListNode *pReversedPreviousTail = NULL;
    ListNode *pStart = head;
    ListNode *pNextStart = NULL;
    while (1) {
        //
        // 按段翻转链表，若 pStart != pReversedHead，代表成功翻转
        //
        pReversedHead = reverseCore(pStart, pNextStart, k);
        if (pStart != pReversedHead) {
            // pReversedPreviousTail 为空，表明这是第一段
            if (pReversedPreviousTail == NULL) {
                head = pReversedHead;
            } else {
                pReversedPreviousTail->next = pReversedHead;
            }
            pReversedPreviousTail = pStart;
        } else {
            if (pReversedPreviousTail == NULL) {

            } else {
                pReversedPreviousTail->next = pStart;
            }
            break;
        }
        if (pNextStart != NULL) {
            pStart = pNextStart;
        } else {
            break;
        }
    }

    return head;
}

int main() {

    return 0;
}