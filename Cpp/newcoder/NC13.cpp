/*
 * 【二叉树的最大深度】
 * 求给定二叉树的最大深度，
最大深度是指树的根结点到最远叶子结点的最长路径上结点的数量。

 输入：
 {1,2,3,4,#,#,5}
 输出：
 3
 */

/**
 * 递归实现
 *
 * 运行时间：4ms
超过54.83%用C++提交的代码
占用内存：908KB
超过40.18%用C++提交的代码
 */
int maxDepth(TreeNode* root) {
    // write code here
    if (root == NULL)
        return 0;

    int r1 = 1+maxDepth(root->left);
    int r2 = 1+maxDepth(root->right);
    return r1 > r2 ? r1 : r2;
}