/**
 * 假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
给定两个这种链表，请生成代表两个整数相加值的结果链表。
例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。

 示例 1：
 输入：[9,3,7],[6,3]
 返回值：{1,0,0,0}
 */



/**
 * 大数加法
 */
string add(string s1, string s2) {
    // 保证 s1 长度大于 s2
    string sum;
    if (s1.length() < s2.length()) {
        string t = s1;
        s1 = s2;
        s2 = t;
    }

    // 从个位开始相加
    int up = 0;  // 进位标志
    int i = s1.length()-1;
    int j = s2.length()-1;
    for (; j >= 0; j--, i--) {
        int t_sum = (s1[i]-'0') + (s2[j]-'0') + up;
        char c = (t_sum%10)+'0';
        // 产生进位
        if (t_sum >= 10) {
            up = 1;
        } else {
            up = 0;
        }
        sum += c;
    }

    // 重合部分已相加完，接下来单独加多出的部分
    for (; i >= 0; i--) {
        int t_sum = (s1[i]-'0') + up;
        char c = (t_sum%10)+'0';
        if (t_sum >= 10) {
            up = 1;
        } else {
            up = 0;
        }
        sum += c;
    }

    // 将累加和字符串进行反序，前面是从个位开始往后保存的
    for (i = 0; i < sum.length()/2; i++) {
        char c = sum[i];
        sum[i] = sum[sum.length()-1-i];
        sum[sum.length()-1-i] = c;
    }

    return sum;
}

/**
 * 运行时间：94ms
超过61.70% 用C++提交的代码
占用内存：31388KB
超过54.64%用C++提交的代码

 思路1：本质上是大数相加的问题。
 先用 while 循环提取链表当中的数字，组成字符串 s1, s2。
 其次对字符串 s1 和 s2 进行大数加法，得到结果s3。
 最后，将 s3 转成链表返回。
 */
ListNode* addInList(ListNode* head1, ListNode* head2) {
    // write code here
    if (head1 == NULL or head2 == NULL)
        return NULL;

    string s1, s2;
    ListNode *p1 = head1;
    ListNode *p2 = head2;

    while (p1 != NULL) {
        char c = p1->val + '0';
        s1 += c;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        char c = p2->val + '0';
        s2 += c;
        p2 = p2->next;
    }

    int n1 = atoi(s1.c_str());
    int n2 = atoi(s2.c_str());
    int sum = n1 + n2;

    string s3 = add(s1, s2);

    ListNode *head3 = NULL;
    p1 = NULL;
    for (int i = 0; i < s3.length(); i++) {
        int n = s3[i]-'0';
        p2 = new ListNode(n);
        if (head3 == NULL) {
            p1 = p2;
            head3 = p1;
        } else {
            p1->next = p2;
            p1 = p2;
        }
    }
    if (p1 != NULL) {
        p1->next = NULL;
    }

    return head3;
}
