/**
     * 叶子距离

     二叉树 n 个节点，编号 1 ~ n，求叶子距离为 k 的叶子节点对数。

        1
       / \
      2   3
     / \
    4   5

    叶子节点之间距离为 3 的对数有 (4,3), (5,3) 两对

    输入：[1,2,3,4,5],3
    输出：2
     */
int leafPairs(TreeNode* root, int k) {
    // write code here

    // 找出所有叶子节点
    vector<TreeNode*> leafNodeVector;

}