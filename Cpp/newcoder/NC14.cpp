/**
 * NC14 按之字形顺序打印二叉树
 *
 * 描述
给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）

输入：
{8,6,10,5,7,9,11}

返回值：
[[8],[10,6],[5,7,9,11]]
 */

/**
 * 明明已经做了，牛客网标记我没做，现在又做了一遍
 */
vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> rt;
    if (pRoot == NULL) {
        return rt;
    }
    queue<TreeNode*> nodeQue;
    int count = 1;
    nodeQue.push(pRoot);
    while (!nodeQue.empty()) {
        stack<int> outStack;
        vector<int> tVec;
        int size = nodeQue.size();
        for (int i = 0; i < size; i++) {
            TreeNode *pNode = nodeQue.front();
            nodeQue.pop();
            if (pNode->left != NULL) {
                nodeQue.push(pNode->left);
            }
            if (pNode->right != NULL) {
                nodeQue.push(pNode->right);
            }
            if (count % 2 == 1) {
                tVec.push_back(pNode->val);
            } else {
                outStack.push(pNode->val);
            }
        }
        if (count % 2 == 0) {
            while (!outStack.empty()) {
                tVec.push_back(outStack.top());
                outStack.pop();
            }
        }
        count++;
        rt.push_back(tVec);
    }
    return rt;
}

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