/**
JZ17 树的子结构

 描述
输入两棵二叉树 A，B，判断 B 是不是 A 的子结构。（ps：我们约定空树不是任意一个树的子结构）

 示例1
输入：{8,8,#,9,#,2,#,5},{8,9,#,2}
返回值：true

*/

bool r = false;

bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot2 == NULL) {
        return true;
    } else if (pRoot1 == NULL) {
        return false;
    }

    bool rLeft, rRight;
    rLeft = rRight = false;

    if (pRoot1->val == pRoot2->val) {
        //
        // 判断左子树
        //
        rLeft = isSubTree(pRoot1->left, pRoot2->left);



        //
        // 判断右子树
        //
        rRight = isSubTree(pRoot1->right, pRoot2->right);
    } else {
        return false;
    }

    return rLeft && rRight;
}

/**
 * 先序遍历
 */
void firstOrder(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (r) {
        return;
    }

    if (pRoot1 == NULL) {
        return;
    }

    // 判断根节点
    r = isSubTree(pRoot1, pRoot2);

    // 左子树
    firstOrder(pRoot1->left, pRoot2);

    // 右子树
    firstOrder(pRoot1->right, pRoot2);
}

/**
 * 思路：先序遍历，然后按个比对
 *
 * 运行时间：4ms
超过8.16% 用C++提交的代码
占用内存：596KB
超过21.22%用C++提交的代码
 */
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot1 == NULL || pRoot2 == NULL) {
        return false;
    }


    firstOrder(pRoot1, pRoot2);

    return r;
}