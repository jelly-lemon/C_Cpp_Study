/*
 * 平衡二叉树
 *
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
平衡二叉树（Balanced Binary Tree），
 具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，
 并且左右两个子树都是一棵平衡二叉树。
 */


/**
 * 思路：递归判断，先获取左右子树的深度，再计算深度差，
 * 以此来判断是否为平衡二叉树
 *
 * 运行时间：3ms
超过29.28%用C++提交的代码
占用内存：504KB
超过64.89%用C++提交的代码
 */
bool IsBalanced_Solution(TreeNode* pRoot) {
    // 如果是子树为空，则认为是平衡的
    if (pRoot == NULL)
        return true;

    // 获取左右子树深度
    int r1 = getDepth(pRoot->left);
    int r2 = getDepth(pRoot->right);
    if (abs(r1-r2) <= 1) {
        return true;
    }

    return false;
}

/**
 * 获取树的深度
 */
int getDepth(TreeNode* pRoot) {
    if (pRoot == NULL)
        return 0;
    int r1 = getDepth(pRoot->left) + 1;
    int r2 = getDepth(pRoot->right) + 1;

    // 返回较大值
    return r1 > r2 ? r1 : r2;
}