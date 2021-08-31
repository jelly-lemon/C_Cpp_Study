/**
 * 二叉树的最大路径和
 *
 * 给定一个二叉树，请计算节点值之和最大的路径的节点值之和是多少。
这个路径的开始节点和结束节点可以是二叉树中的任意节点

 例如：
给出以下的二叉树，
        1
       / \
      2   3

返回的结果为 6，即：2 -> 1 -> 3

 示例 1
输入：{-2,1}
返回值：1

 示例 2
 输入：{-2,#,-3}
     -2
       \
        -3

返回值：-2

 难点：
 - 任意起点，任意终点。起点不止是根节点，还有叶子节点。
 - 节点中还有负数。
 */

int getMaxPathValue(TreeNode *root) {
    if (root == NULL) {
        return INT_MIN;
    }

    // write code here
    int leftMax = getMaxPathValue(root->left);
    int rightMax = getMaxPathValue(root->right);

    int max = 0;
    if (leftMax > 0) {
        max += leftMax;
    }
    if (root->val > 0) {
        max += root->val;
    }
    if (rightMax > 0) {
        max += rightMax;
    }

    // 说明三者都小于 0，矮子中挑高个子
    if (max == 0) {
        if (leftMax >= rightMax) {
            max = leftMax;
        } else {
            max = rightMax;
        }
        if (max < root->val) {
            max = root->val;
        }
    }

    return max;
}

/**
 * 思路：左子树最大路径和 + 根节点 + 右子树最大路径和
 *
 * 10/20 组用例通过
 *
 * 存在的问题：左子树 + 根节点 + 右子树 这三部分不一定能连成一个路径啊！
 */
int maxPathSum(TreeNode* root) {
    if (root == NULL) {
        return INT_MIN;
    }

    return getMaxPathValue(root);
}