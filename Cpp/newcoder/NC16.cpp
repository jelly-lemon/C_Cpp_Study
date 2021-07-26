bool isSymmetricCore(TreeNode *p1, TreeNode *p2) {
    if (p1 != NULL && p2 != NULL) {
        if (p1->val != p2->val) {
            return false;
        }
    } else if ((p1 == NULL && p2 != NULL) || p1 != NULL && p2 == NULL) {
        return false;
    } else {
        return true;
    }


    bool r1 = isSymmetricCore(p1->left, p2->right);
    bool r2 = isSymmetricCore(p1->right, p2->left);

    return r1 && r2;
}
/**
 *
 * 运行时间：4ms
超过39.87% 用C++提交的代码
占用内存：476KB
超过50.15%用C++提交的代码
 */
bool isSymmetric(TreeNode* root) {
    // write code here
    if (root == NULL) {
        return true;
    }

    return isSymmetricCore(root->left, root->right);
}