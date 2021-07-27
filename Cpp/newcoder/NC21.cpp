/**
 * 描述
将一个链表 m 位置到 n 位置之间的区间反转，要求时间复杂度 O(n)，空间复杂度 O(1)。
例如：
给出的链表为 1→2→3→4→5→NULL, m=2,n=4,
返回 1→4→3→2→5→NULL.
注意：
给出的 m,n 满足以下条件：
链表长度1≤m≤n≤链表长度
示例1
输入：
{1,2,3,4,5},2,4
复制
返回值：
{1,4,3,2,5}

预期输入：{3,5},1,1
预期输出：{3,5}
 */


void reverseCore(ListNode *pStart, int len) {
    if (pStart == NULL || pStart->next == NULL) {
        return;
    }

    ListNode *p1, *p2, *p3;
    p1 = NULL;
    p2 = pStart;
    p3 = p2->next;
    for (int i = 0; i < len; i++){
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if (p3 != NULL) {
            p3 = p3->next;
        } else {
            break;
        }
    }
}


/**
 *
 * 运行时间：3ms
超过52.77% 用C++提交的代码
占用内存：524KB
超过23.64%用C++提交的代码
 */
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* pSubStartPrevious = new ListNode(0);
    pSubStartPrevious ->next = head;

    //
    // 找出子串前一个节点，以及字串头节点
    //
    for (int i = 0; i < m-1; i++) {
        pSubStartPrevious = pSubStartPrevious->next;
    }
    ListNode *pSubStart = pSubStartPrevious->next;

    //
    // 找出字串尾节点，以及后一个节点
    //
    ListNode *pSubEnd = head;
    ListNode *pSubEndNext = NULL;
    for (int i = 0; i < n-1; i++) {
        pSubEnd = pSubEnd->next;
    }
    pSubEndNext = pSubEnd->next;

    //
    // 反转子串
    //
    reverseCore(pSubStart, n-m+1);

    //
    // 缝合子串
    //
    pSubStartPrevious->next = pSubEnd;
    pSubStart->next = pSubEndNext;

    //
    // 返回翻转链表的头节点
    //
    if (m == 1) {
        return pSubStartPrevious->next;
    }

    return head;
}