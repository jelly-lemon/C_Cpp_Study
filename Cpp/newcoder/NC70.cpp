/**
 链表排序

给定一个无序单链表，实现单链表的排序(按升序排序)。

 示例1
输入：[1,3,2,4,5]
返回值：{1,2,3,4,5}
*/


/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

/**
 * 自定义比较函数
 */
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }

};

class Solution {
public:
    /**
     * 思路 1：借助小顶堆
     *
     * 时间复杂度：O(nlogn)，空间复杂度：O(n)
     *
运行时间：16ms
超过77.98% 用C++提交的代码
占用内存：1952KB
超过69.58%用C++提交的代码
     */
    ListNode* sortInList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        // 遍历数据，放入小顶堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        ListNode *p = head;
        while(p) {
            minHeap.push(p);
            p = p->next;
        }

        // 依次取堆顶元素
        ListNode *newHead = NULL;
        p = NULL;
        while (!minHeap.empty()) {
            if (newHead == NULL) {
                p = newHead = minHeap.top();
                minHeap.pop();
            } else {
                p->next = minHeap.top();
                p = p->next;
                minHeap.pop();
            }
        }
        p->next = NULL;

        return newHead;
    }


    /**
     * 归并排序
     *
     * 思路：先利用快慢指针找出链表的中点，然后分为两个链表，一直分
     */
    ListNode* sortInList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }

        // 找到尾节点
        ListNode *p = head;
        while (p->next) {
            p = p->next;
        }
        p = mergeSort(head, p);

        return p;
    }

    /**
    编程时太容易出错了！很难！

    运行时间：14ms
超过84.63% 用C++提交的代码
占用内存：1552KB
超过95.81%用C++提交的代码
*/
    ListNode *mergeSort(ListNode *begin, ListNode *end) {
        // 【易错点】end 表示子链表尾节点，不要设置成 [) 模式，应该设置为 [] 模式
        if (begin == NULL) {
            // 没有节点
            return NULL;
        } else if (begin == end) {
            // 只有一个节点
            begin->next = NULL;
            return begin;
        } else if (begin->next == end) {
            // 只有两个节点
            if (begin->val <= end->val) {
                end->next = NULL;
                return begin;
            } else {
                ListNode *t = end->next;
                end->next = begin;
                begin->next = NULL;
                return end;
            }
        }

        ListNode *fastP = begin;
        ListNode *slowP = begin;
        // 【易错点】子链表尾节点的 next 不是 NULL
        while (fastP != end->next) {
            if (fastP->next != end->next) {
                fastP = fastP->next;
                if (fastP->next != end->next) {
                    fastP = fastP->next;
                } else {
                    break;
                }
            } else {
                break;
            }
            slowP = slowP->next;
        }

        // 分
        // 【易错点】slowP->next 的值被第一次 mergeSort 改变了，slowP->next 已经不是原来的值了
        ListNode *subBegin = slowP->next;
        ListNode *p1 = mergeSort(begin, slowP);
        ListNode *p2 = mergeSort(subBegin, end);

        // 合
        ListNode newHead = {0};
        ListNode *p = &newHead;
        while (p1 || p2) {
            if (p1 != NULL && p2 != NULL) {
                if (p1->val <= p2->val) {
                    p->next = p1;
                    p = p->next;
                    p1 = p1->next;
                } else {
                    p->next = p2;
                    p = p->next;
                    p2 = p2->next;
                }
            } else if (p1 != NULL) {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            } else if (p2 != NULL) {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        p->next = NULL;

        return newHead.next;
    }
};