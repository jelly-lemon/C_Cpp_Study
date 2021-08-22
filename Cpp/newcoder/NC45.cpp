/**
 分别按照二叉树先序，中序和后序打印所有的节点。

 输入：{1,2,3}
 输出：[[1,2,3],[2,1,3],[2,3,1]]

 迭代遍历：会用到栈
 */




/**
 * 思路 1：递归遍历
 *
 * 运行时间：4ms
超过31.42% 用C++提交的代码
占用内存：376KB
超过65.50%用C++提交的代码
 */
vector<vector<int> > threeOrders(TreeNode* root) {
    // write code here
    vector<vector<int>> result;

    if (root == NULL)
    return result;
    result.push_back(preOrder(root));
    result.push_back(midOrder(root));
    result.push_back(postOrder(root));

    return result;
}

/**
 * 先序，递归
 */
vector<int> preOrder(TreeNode* root) {
    vector<int> v;
    if (root == NULL)
        return v;

    v.push_back(root->val);

    vector<int> left = preOrder(root->left);
    v.insert(v.end(), left.begin(), left.end());

    vector<int> right = preOrder(root->right);
    v.insert(v.end(), right.begin(), right.end());

    return v;
}

/**
 * 中序遍历，递归
 */
vector<int> midOrder(TreeNode* root) {
    vector<int> v;
    if (root == NULL)
        return v;

    vector<int> left = midOrder(root->left);
    v.insert(v.end(), left.begin(), left.end());

    v.push_back(root->val);

    vector<int> right = midOrder(root->right);
    v.insert(v.end(), right.begin(), right.end());

    return v;
}

/**
 * 迭代中序遍历

 思路：借助栈来完成迭代遍历。
 首先将根节点入栈。 只要栈不为空，就执行：
 1. 根节点入栈，如果存在左子树，左子树入栈。
 2. 如果不存在，立即访问该根节点。
 3. 如果存在右子树，右子树入栈。
 */
vector<int> midOrderByIteration(TreeNode* root) {
    vector<int> v;
    if (root == NULL)
        return v;

    stack<TreeNode*> myStack;
    TreeNode *p = root;
    myStack.push(p);

    while (!myStack.empty()) {
        p = myStack.top();

        // 如果存在左子树
        if (p->left) {
            myStack.push(p->left);
        } else {
            // 不存在左子树，访问根节点
            myStack.pop();
            v.push_back(p->val);

            // 如果存在右子树
            if (p->right) {
                myStack.push(p->right);
            }
        }

    }

    return v;
}

/**
 * 后续，递归
 */
vector<int> postOrder(TreeNode* root) {
    vector<int> v;
    if (root == NULL)
        return v;

    vector<int> left = postOrder(root->left);
    v.insert(v.end(), left.begin(), left.end());

    vector<int> right = postOrder(root->right);
    v.insert(v.end(), right.begin(), right.end());

    v.push_back(root->val);

    return v;
}