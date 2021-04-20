/**
 * 反转链表
 */
#include <stdio.h>

/**
 * 链表节点
 */
struct ListNode {
    int value;
    ListNode *next;
};


/**
 * 创建链表
 */
ListNode* createLinkedList(int a[], int len) {
    if (a == NULL || len == 0)
        return NULL;

    ListNode *pHead = NULL;
    ListNode *pPre = NULL;
    int i;
    for (i = 0; i < len; i++) {
        ListNode *pNew = new ListNode;
        pNew->value = a[i];
        if (pHead == NULL) {
            pHead = pNew;
            pPre = pHead;
            continue;
        }
        pPre->next = pNew;
        pPre = pNew;
    }
    pPre->next = NULL;

    return pHead;
}

/**
 * 打印链表
 */
void printList(ListNode *pHead) {
    if (pHead == NULL)
        return;
    ListNode *p1 = pHead;
    while(p1) {
        printf("%d ", p1->value);
        p1 = p1->next;
    }
    printf("\n");
}


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

    // TODO
    while (1) {

    }
}

/**
 * 反转链表
 */
ListNode* reverseLinkedList(ListNode *pHead) {
    if (pHead == NULL)
        return NULL;
    if (pHead->next == NULL)
        return pHead;
    ListNode *p1 = NULL;
    ListNode *p2 = pHead;
    ListNode *p3 = p2->next;
    while (p3) {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    return p2;
}

void test_1() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    ListNode *pHead = createLinkedList(a, 10);
    printf("before:");
    printList(pHead);
    pHead = reverseLinkedList(pHead);
    printf("after:");
    printList(pHead);
}

int main() {
    test_1();

    return 0;
}