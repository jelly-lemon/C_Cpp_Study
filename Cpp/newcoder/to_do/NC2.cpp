/*
 * 将给定的单链表 L：L0 -> L1 -> ... -> Ln-1 -> Ln
 * 重新排序为：L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
 * 要求使用原地算法，不能只改变节点内部的值，需要对实际的节点进行交换。
例如：
对于给定的单链表{10,20,30,40}，将其重新排序为{10,40,20,30}.
 */

/**
 * 思路 1：把链表首地址用数组保存起来，但是运行超内存
 */
void reorderList(ListNode *head) {
    // 先遍历一遍
    int count;
    int i, j;

    if (head == NULL)
        return;
    count = 1;
    ListNode *p = head;
    while(p->next != NULL) {
        count++;
        p = p->next;
    }
    if (count <= 2)
        return;

    ListNode* a[count];
    p = head;
    i = 0;
    while(p->next != NULL) {
        a[i++] = p;
        p = p->next;
    }

    for (i = 0, j = count-1; i < j; j--) {
        a[i]->next = a[j];
        i++;
        if (i < j) {
            a[j]->next = a[i];
        } else {
            a[j]->next = NULL;
            break;
        }
    }
}

/**
 * 思路 2：首先找到中间节点，其次反转后半链表，
 * 最后合并两个链表
 */
void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    // 快慢指针找到中间节点
    // 偶数长度：中间节点为右边一个
    // 奇数长度：中间节点为正中间
    ListNode *pFast, *pSlow;
    pFast = pSlow = head;
    while (pFast != NULL && pFast->next != NULL) {
        pSlow = pSlow->next;
        pFast = pFast->next;
        pFast = pFast->next;
    }

    // 反转后半链表
    ListNode *p1 = pSlow;
    ListNode *p2 = p1->next;
    ListNode *p3;
    p1->next = NULL;
    if (p2 != NULL)  {
        while (p2->next != NULL) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        p2->next = p1;
    }

    // TODO 合并两个链表


}