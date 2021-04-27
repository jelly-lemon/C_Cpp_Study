/*
 运行时间：3ms
超过34.68%用C++提交的代码
占用内存：352KB
超过85.49%用C++提交的代码
 */
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    // write code here
    vector<vector<int> > r;
    queue<TreeNode*> q;
    if (root != NULL)
        q.push(root);
    else
        return r;
    TreeNode* p;
    int count = 0;
    while(!q.empty()) {
        vector<int> v;
        stack<int> s;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            p = q.front();
            q.pop();
            if (count % 2 == 1){
                s.push(p->val);
            }
            else {
                v.push_back(p->val);
            }

            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        if (count % 2 == 1) {
            while (!s.empty()) {
                v.push_back(s.top());
                s.pop();
            }
        }
        r.push_back(v);
        count++;
    }
    return r;
}