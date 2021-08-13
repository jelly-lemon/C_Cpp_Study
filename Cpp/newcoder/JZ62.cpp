/**
 * JZ62 二叉搜索树的第k个结点
 *
 * 描述
给定一棵二叉搜索树，请找出其中的第k小的TreeNode结点。
示例1
输入：{5,3,7,2,4,6,8},3
返回值：4

 说明：
按结点数值大小顺序第三小结点的值为4
 */

/**
 * 思路：使用对类成员
 *
运行时间：6ms
超过2.25% 用C++提交的代码
占用内存：752KB
超过9.86%用C++提交的代码*/
class Solution {
    TreeNode *target = NULL;
    int count = 0;
    int targetK = 0;

public:
    void inorderTranversal(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        inorderTranversal(pRoot->left);

        if (count == targetK) {
            return;
        } else {
            count++;
            if (count == targetK) {
                target = pRoot;
            }
        }


        inorderTranversal(pRoot->right);
    }

    TreeNode *KthNode(TreeNode *pRoot, int k) {
        targetK = k;

        if (pRoot == NULL) {
            return NULL;
        }

        int count = 0;
        inorderTranversal(pRoot);

        return target;
    }


};