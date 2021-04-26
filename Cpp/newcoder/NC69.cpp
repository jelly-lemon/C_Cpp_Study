/*
 输入一个链表，输出该链表中倒数第k个结点。
如果该链表长度小于k，请返回空。
 */

/*
 运行时间：4ms
超过40.72%用C++提交的代码
占用内存：600KB
超过0.78%用C++提交的代码
 */
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if (pHead == NULL)
            return NULL;
        if (k < 1)
            return NULL;

        int i = 0;
        ListNode* pFast = pHead;
        for (i = 1; i < k; i++) {
            pFast = pFast->next;
            if (pFast == NULL)
                return NULL;
        }
        ListNode* pSlow = pHead;
        while (pFast->next != NULL) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};