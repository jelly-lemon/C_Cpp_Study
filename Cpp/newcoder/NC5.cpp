/*
 * 给定一个仅包含数字 0−9 的二叉树，每一条从根节点到叶子节点的路径都可以用一个数字表示。
例如根节点到叶子节点的一条路径是1 -> 2 -> 3,那么这条路径就用 123 来代替。
找出根节点到叶子节点的所有路径表示的数字之和
例如：
        1
       / \
      2   3

这颗二叉树一共有两条路径，
根节点到叶子节点的路径 1 -> 2 用数字 12 代替
根节点到叶子节点的路径 1 -> 3 用数字 13 代替
所以答案为 12+13=25
 */

int getSum(TreeNode *root, string path) {
    static int sum  = 0;

    if (root == NULL) {
        return 0;
    }
    path += to_string(root->val);
    if (root->left == NULL && root->right == NULL) {
        //
        int n = atoi(path.c_str());
        sum += n;
    } else {
        getSum(root->left, path);
        getSum(root->right, path);
    }

    return sum;
}

/**
运行时间：3ms
超过44.21% 用C++提交的代码
占用内存：408KB
超过73.73%用C++提交的代码
*/
int sumNumbers(TreeNode* root) {
    // write code here
    string s;
    return getSum(root, s);
}
