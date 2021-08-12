/**
 * 描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

 示例1
输入：{1,2,3,4,5,#,6,#,#,7}
返回值：4
 */

/**
    运行时间：3ms
超过30.84% 用C++提交的代码
占用内存：532KB
超过22.33%用C++提交的代码
*/
int TreeDepth(TreeNode* pRoot) {
    if (pRoot == NULL) {
        return 0;
    }

    int leftHigh = TreeDepth(pRoot->left);
    int rightHigh = TreeDepth(pRoot->right);
    int maxHigh = (leftHigh > rightHigh ? leftHigh : rightHigh) + 1;

    return maxHigh;
}