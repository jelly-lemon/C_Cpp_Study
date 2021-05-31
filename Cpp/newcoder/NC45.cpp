/*
 * 分别按照二叉树先序，中序和后序打印所有的节点。
 * 输入：{1,2,3}
 * 输出：[[1,2,3],[2,1,3],[2,3,1]]
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