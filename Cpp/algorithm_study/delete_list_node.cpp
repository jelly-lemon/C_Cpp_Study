/**
 * 给出链表头节点指针和待删除节点指针，
 * 要求O(1)时间复杂度删除链表节点
 */

#include <list>
#include <stdio.h>
#include <string.h>
using namespace std;


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
 * 删除节点
 *
 * @param pHead 头节点指针
 * @param pDelete 带删除节点指针
 */
void deleteListNode(ListNode *pHead, ListNode *pDelete) {
    if (pHead == NULL || pDelete == NULL)
        return;

    ListNode *pDeleteNext = pDelete->next;
    if (pDeleteNext != NULL) {
        memcpy(pDelete, pDeleteNext, sizeof(ListNode));
        delete pDeleteNext;
    } else {
        // pDelete->next 为 NULL，说明这是末尾节点，这种情况只能从头遍历
        ListNode *p = pHead;
        while(p->next->next != NULL) {
            p = p->next;
        }
        p->next = NULL;
        delete pDelete;
    }
}

/**
 * 删除中间节点
 */
void test_1() {
    int a[10] = {1, 3, 5, 2, 4, 6, 8, 7, 9, 0};
    ListNode* pHead = createLinkedList(a, 10);
    ListNode* pDelete = pHead->next->next->next;    // 想要删除第四个
    printf("delete 4th number\n");
    printf("before:");
    printList(pHead);
    deleteListNode(pHead, pDelete);
    printf("after:");
    printList(pHead);
}

/**
 * 删除末尾节点
 */
void test_2() {
    int a[10] = {1, 3, 5, 2, 4, 6, 8, 7, 9, 0};
    ListNode* pHead = createLinkedList(a, 10);
    ListNode* pDelete = pHead->next->next->next->next->next->next->next->next->next;    // 想要删除第四个
    printf("delete 10th number\n");
    printf("before:");
    printList(pHead);
    deleteListNode(pHead, pDelete);
    printf("after:");
    printList(pHead);
}



int main() {
    test_2();


    return 0;
}