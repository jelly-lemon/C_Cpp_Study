/*
 * 输入某二叉树的前序遍历和中序遍历的结果，
 * 请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
 * 则重建二叉树并返回。
 *
 * 输入：[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
 * 输出：{1,2,5,3,4,6,7}
 */


/**
 * 重建二叉树 = 找到根节点 + 重建左子树 + 重建右子树
 */
TreeNode* rebuildTree(vector<int>& xianxu, vector<int>& zhongxu) {
    if (xianxu.size() == 0 || zhongxu.size() == 0)
        return NULL;
    int val = xianxu[0];

    auto *root = new TreeNode(val);

    for (int i = 0; i < zhongxu.size(); i++) {
        if (zhongxu[i] == val) {
            int leftLen = i;
            vector<int> xianxu_left(xianxu.begin()+1, xianxu.begin()+leftLen+1);
            vector<int> zhongxu_left(zhongxu.begin(), zhongxu.begin()+leftLen);
            root->left = rebuildTree(xianxu_left, zhongxu_left);

            vector<int> xianxu_right(xianxu.begin()+1+leftLen, xianxu.end());
            vector<int> zhongxu_right(zhongxu.begin()+leftLen+1, zhongxu.end());
            root->right = rebuildTree(xianxu_right, zhongxu_right);
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