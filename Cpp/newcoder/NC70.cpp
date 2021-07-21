/**
* 给定一个无序单链表，实现单链表的排序(按升序排序)。
*/


/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }

};

class Solution {
public:
    /**
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        // write code here
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        ListNode *p = head;
        while(p) {
            minHeap.push(p);
            p = p->next;
        }
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
};