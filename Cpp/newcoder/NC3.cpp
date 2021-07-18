/*
 对于一个给定的链表，返回环的入口节点，如果没有环，返回null
 拓展：
 你能给出不利用额外空间的解法么？
 【难点】如何计算环的长度
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 运行时间：11ms
超过49.34%用C++提交的代码
占用内存：1096KB
超过55.13%用C++提交的代码

 思路：快慢指针
 */
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode* pSlow = head;
    ListNode* pFast = head;
    int nSlow = 0;
    while (pFast != NULL) {
        if (pFast->next == NULL)
            return NULL;
        else {
            if (pFast->next->next == NULL)
                return NULL;
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            nSlow++;

            if (pFast == pSlow || pFast->next == pSlow){
                break;
            }
        }
    }
    // 计算回环长度
    int nCircle = 1;
    pFast = pSlow->next;
    while (pFast != pSlow) {
        nCircle++;
        pFast = pFast->next;
    }

    pSlow = pFast = head;
    for (int i = 0; i < nCircle; i++) {
        pFast = pFast->next;
    }
    for (int i = 0; i < nSlow; i++) {
        // 纯回环的情况
        if (pFast == pSlow)
            return pFast;

        if (pFast->next == pSlow->next)
            return pFast->next;
        else {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
    }

    return NULL;
}