/**
 * 反转链表
 *
 * 个人评价：【简单】
 * 主要考察对链表的理解、使用指针对节点进行链接的操作

 头插法：每次插入节点都插入在链表首
 尾插法：每次插入节点都插在链表尾
 */

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    /**
     * 运行时间：3ms
超过26.15% 用C++提交的代码
占用内存：516KB
超过62.90%用C++提交的代码
     */
    ListNode* ReverseList(ListNode* pHead) {
        //
        // 非法输入检查：空、只有一个节点
        //
        if (pHead == NULL)
            return NULL;
        if (pHead->next == NULL)
            return pHead;

        //
        // 借助 3 个指针变量反转链表
        // 【关键点】p1 为 NULL，p2 为第一个节点，p3 为第三个节点，while 结束后 p2 指向最后一个节点
        //
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

    /**
     * 头插法反转链表
     *
     * 遍历旧链表，每次插入到新链表头部
     *
     * 运行时间：3ms
超过26.15% 用C++提交的代码
占用内存：524KB
超过61.50%用C++提交的代码
     */
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) {
            return NULL;
        }
        if (pHead->next == NULL) {
            return pHead;
        }

        ListNode newHead;
        newHead.next = pHead;
        ListNode *p = pHead->next;
        ListNode *pNext = p->next;
        pHead->next = NULL;
        while (p) {
            ListNode *p1 = newHead.next;
            newHead.next = p;
            p->next = p1;
            p = pNext;
            if (pNext) {
                pNext = pNext->next;
            }
        }

        return newHead.next;
    }
};