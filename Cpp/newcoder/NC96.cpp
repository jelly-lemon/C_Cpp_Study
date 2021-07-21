/**
 * 给定一个链表，请判断该链表是否为回文结构。
 */


/**
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
bool isPail(ListNode* head) {
    if (head == NULL) {
        return false;
    }
    // write code here
    vector<int> arr;
    ListNode *p = head;
    while(p) {
        arr.push_back(p->val);
        p = p->next;
    }

    int len = arr.size();
    for (int i = 0; i < len/2; i++) {
        if (arr[i] != arr[len-1-i]) {
            return false;
        }
    }

    return true;
}