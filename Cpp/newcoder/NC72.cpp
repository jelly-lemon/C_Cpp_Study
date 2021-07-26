/**
     * 运行时间：3ms
超过54.56% 用C++提交的代码
占用内存：412KB
超过36.51%用C++提交的代码
     */
TreeNode* Mirror(TreeNode* pRoot) {
    if (pRoot == NULL) {
        return pRoot;
    }

    // write code here
    queue<TreeNode*> nodeQue;

    nodeQue.push(pRoot);
    while (!nodeQue.empty()) {
        TreeNode *p = nodeQue.front();
        nodeQue.pop();
        TreeNode *t = p->left;
        p->left = p->right;
        p->right = t;
        //
        // 【特别容易忘记】放入队列前，先判断该节点是否为空，为空就不放入了
        //
        if (p->left != NULL) {
            nodeQue.push(p->left);
        }
        if (p->right != NULL) {
            nodeQue.push(p->right);
        }
    }

    return pRoot;
}