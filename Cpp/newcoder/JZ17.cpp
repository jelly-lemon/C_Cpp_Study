/**
JZ17 树的子结构

 描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

 示例1
输入：{8,8,#,9,#,2,#,5},{8,9,#,2}
返回值：true

*/

bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
    int rLeft, rRight;
    // 判断左子树
    if (pRoot2->left && pRoot1->left) {
        if (pRoot2->left->val == pRoot1->left->val) {
            rLeft = isSubTree(pRoot1->left, pRoot2->left);
        } else {
            rLeft = false;
        }
    }


    // 判断右子树
    if (pRoot2->right && pRoot1->right) {
        if (pRoot2->right->val == pRoot1->right->val) {
            rRight = isSubTree(pRoot1->right, pRoot2->right);
        } else {
            rRight = false;
        }
    }

    return rLeft && rRight;
}

bool firstOrder(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot1 == NULL) {
        return false;
    }

    // 找到相同起点
    if (pRoot1->val == pRoot2->val) {
        bool r = isSubTree(pRoot1, pRoot2);
        if (r) {
            return r;
        }
    } else {
        bool r = firstOrder(pRoot1->left, pRoot2);
        if (r) {
            return r;
        }

        r = firstOrder(pRoot1->right, pRoot2);
        if(r) {
            return r;
        }
    }

    return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot1 == NULL || pRoot2 == NULL) {
        return false;
    }


    return firstOrder(pRoot1, pRoot2);

    return false;
}