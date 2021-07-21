/*
 * 给定一个二叉树和一个值sum，请找出所有的根节点到叶子节点的节点值之和等于 sum 的路径，
例如：
给出如下的二叉树， sum=22
         5
       /   \
     4      8
   /  \      \
  1   11      9
      / \
     2   7

返回
[
[5,4,11,2],
[5,8,9]
]
 */

/**
 * 运行时间：4ms
超过81.83% 用C++提交的代码
占用内存：744KB
超过86.91%用C++提交的代码

 思路 1：深度优先（先根遍历）
 */
vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int> > rt;

    if (root == NULL)
        return rt;

    vector<int> path;
    path.push_back(root->val);
    // 只有一个根节点的情况
    if (root->left == NULL and root->right == NULL) {
        // 根节点的值等于 sum
        if (root->val == sum)
            rt.push_back(path);
    }
    if (root->left != NULL)
        preOrder(root->left, path, sum, rt);
    if (root->right != NULL)
        preOrder(root->right, path, sum, rt);

    return rt;
}

void preOrder(TreeNode *root, vector<int> path, const int &sum, vector<vector<int> > &rt) {
    // 若该节点为叶节点
    path.push_back(root->val);
    if (root->left == NULL and root->right == NULL) {
        int pathSum = 0;
        for (auto t:path) {
            pathSum += t;
        }
        if (pathSum == sum) {
            rt.push_back(path);
        }
    } else {
        if (root->left != NULL)
            preOrder(root->left, path, sum, rt);
        if (root->right != NULL)
            preOrder(root->right, path, sum, rt);
    }
}
