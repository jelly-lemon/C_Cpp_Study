/*
 * 输入某二叉树的前序遍历和中序遍历的结果，
 * 请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 * 输入：[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
 * 输出：{1,2,5,3,4,6,7} （输出按层遍历的结果）
 */


/**
 * 重建二叉树 = 找到根节点 + 重建左子树 + 重建右子树
 */
TreeNode* rebuildTree(vector<int>& preSequence, vector<int>& inorderSequence) {
    if (preSequence.size() == 0 || inorderSequence.size() == 0) {
        return NULL;
    }

    // 创建根节点
    int val = preSequence[0];
    auto *root = new TreeNode(val);

    for (int i = 0; i < inorderSequence.size(); i++) {
        // 找出根节点在中序遍历中的位置
        if (inorderSequence[i] == val) {
            // 得到左子树长度
            int leftLen = i;

            // 重建左子树
            vector<int> preSequence_left(preSequence.begin()+1, preSequence.begin()+leftLen+1);
            vector<int> inorderSequence_left(inorderSequence.begin(), inorderSequence.begin()+leftLen);
            root->left = rebuildTree(preSequence_left, inorderSequence_left);

            // 重建右子树
            vector<int> preSequence_right(preSequence.begin()+1+leftLen, preSequence.end());
            vector<int> inorderSequence_right(inorderSequence.begin()+leftLen+1, inorderSequence.end());
            root->right = rebuildTree(preSequence_right, inorderSequence_right);

            return root;
        }
    }
    return NULL;
}


/**
 * 思路 1：和题目 NC136 相同
 *
 * 运行时间：3ms
超过73.32% 用C++提交的代码
占用内存：504KB
超过70.81%用C++提交的代码
 */
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    return rebuildTree(pre, vin);
}