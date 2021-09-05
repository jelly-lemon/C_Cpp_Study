#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
    输入多个长度不等的链表，依次取每个链表头节点组成新链表。

     * 输入：[{1,2,3},{4,5},{7,8,9,10,11,12}]
       输出：{1,4,7,2,5,8,3,9,10,11,12}

输入：[{1,3},{},{2}]
输出：[{1,3},{},{2}]

 AC
     */
ListNode* solve(vector<ListNode*>& a) {
    if (a.size() == 0) {
        return NULL;
    }
    ListNode *p = NULL;
    ListNode *newHead = NULL;
    vector<ListNode*> oldList(a);
    while (1) {
        bool isAllNULL = true;
        vector<ListNode*> newList;
        for (auto &p1 : oldList) {
            if (p1 == NULL) {
                continue;
            } else {
                if (p1->next != NULL) {
                    newList.push_back(p1->next);
                }
            }
            if (p == NULL) {
                if (p1 != NULL) {
                    p = p1;
                    newHead = p;
                    isAllNULL = false;
                }
            } else {
                if (p1 != NULL) {
                    p->next = p1;
                    p = p->next;
                    p1 = p1->next;
                    isAllNULL = false;
                }
            }
            if (isAllNULL) {
                break;
            }
        }
        if (isAllNULL) {
            break;
        }
        oldList = newList;
    }
    return newHead;
}