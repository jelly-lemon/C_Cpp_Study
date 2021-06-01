/*
 * 给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
例如：
给出的链表为1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5, 返回 1→2→5.
给出的链表为1→1→1→2→3, 返回 2→3.

 输入：{1,2,2}
 返回值：{1}


 */

/** 思路 1：三个指针变量 p1, p2, p3 来删除重复的节点
 * 【难点】要考虑很多边界情况
 *
 * 运行时间：3ms
超过52.73% 用C++提交的代码
占用内存：388KB
超过71.76%用C++提交的代码
 */
ListNode* deleteDuplicates(ListNode* head) {
    // write code here
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    ListNode *p1, *p2, *p3;

    p1 = head;
    p2 = p1->next;
    p3 = p2->next;

    // 前面几个元素相同
    while (p1->val == p2->val) {
        int val = p2->val;
        while (p1->val == val) {
            delete p1;
            p1 = p2;
            p2 = p3;
            if (p3 != NULL)
                p3 = p3->next;
            if (p1 == NULL)
                return NULL;
        }
        // 只剩一个节点了
        if (p1->next == NULL)
            return p1;
    }
    head = p1;

    // 只有两个节点
    if (p3 == NULL) {
        if (p1->val == p2->val)
            return NULL;
        else
            return head;
    }


    // 3个或3个以上节点
    while (p3 != NULL) {
        if (p2->val == p3->val) {
            int val = p2->val;
            while (p2->val == val) {
                p1->next = p3;
                delete p2;
                p2 = p3;
                if (p2 == NULL)
                    break;
                else
                    p3 = p2->next;
            }
        } else {
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }

    }

    return head;
}