/**
 * 翻转链表
 */

#include <stdio.h>

struct ListNode {
    int value;
    struct ListNode *next;
};

/**
 * 比较两个链表是否相等，有头节点
 *
 * -1 表示不相等，0 表示相等
 */
int compare(ListNode *p1, ListNode *p2) {
    if (p1 == NULL || p2 == NULL) {
        return -1;
    }
    p1 = p1->next;
    p2 = p2->next;

    while (1) {

    }
}

int main() {


    return 0;
}