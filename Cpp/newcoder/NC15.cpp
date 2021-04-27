/*
 运行时间：4ms
超过17.47%用C++提交的代码
占用内存：352KB
超过92.47%用C++提交的代码
 */
vector<vector<int> > levelOrder(TreeNode* root) {
    // write code here
    vector<vector<int> > r;
    queue<TreeNode*> q;
    if (root != NULL)
        q.push(root);
    else
        return r;
    TreeNode* p;
    while(!q.empty()) {
        vector<int> v;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            p = q.front();
            q.pop();
            v.push_back(p->val);
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        r.push_back(v);
    }
    return r;
}