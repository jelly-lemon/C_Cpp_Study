/*
 * 请根据二叉树的前序遍历，中序遍历恢复二叉树，并打印出二叉树的右视图
 * 备注：
 * 二叉树每个节点的值在区间[1,10000]内，且保证每个节点的值互不相同。
 * 输入：
 * [1,2,4,5,3],[4,2,5,1,3]
 * 返回值：
 * [1,3,5]
 *
 * 【难点】右视图是什么？面向二叉树，从上到下打印每一层最右边的元素
 *
 * 个人感觉，很难，不构建一颗真正的二叉树时，该如何解决问题呢？
 */

#include <vector>
#include <list>
#include <iostream>
using namespace std;
struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

void printVector(vector<int> v) {
    for (auto k:v) {
        cout << k << " ";
    }
    cout << endl;
}

/**
 * 重建二叉树
 */
TreeNode* rebuildTree(vector<int>& xianxu, vector<int>& zhongxu) {
    if (xianxu.size() == 0 || zhongxu.size() == 0)
        return NULL;
    auto *root = new TreeNode;

    int value = xianxu[0];
    root->value = value;
    for (int i = 0; i < zhongxu.size(); i++) {
        if (zhongxu[i] == value) {
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

vector<int> getRightView(TreeNode* root) {
    vector<int> rightView;
    list<TreeNode*> layerList;

    if(root == NULL)
        return rightView;

    // 按层遍历
    layerList.push_back(root);
    while (layerList.size() != 0) {
        int len = layerList.size();
        for (int i = 0; i < len; i++) {
            TreeNode *p = layerList.front();
            layerList.pop_front();
            if (p->left != NULL) {
                layerList.push_back(p->left);
            }
            if (p->right != NULL) {
                layerList.push_back(p->right);
            }
            if (i+1 == len) {
                rightView.push_back(p->value);
            }
        }
    }
    return rightView;
}

/**
 * 思路 1：恢复二叉树，按层遍历，取每一层最末尾的元素
 * 【难点】如何恢复二叉树？二叉树怎么存？如果要构建一颗二叉树，会不会太复杂了？
 *
 * 运行时间：3ms
超过10.08% 用C++提交的代码
占用内存：484KB
超过15.09%用C++提交的代码
 */
vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
    TreeNode *root = rebuildTree(xianxu, zhongxu);
    return getRightView(root);
}


/**
 * 思路 2：递归
 */
//vector<int> solve_2(vector<int>& xianxu, vector<int>& zhongxu) {
//        // TODO
//        vector<int> r;
//        if (xianxu.size() == 0)
//            return r;
//
//        int i;
//        for (i = 0; i < zhongxu.size(); i++) {
//            if (zhongxu[i] == xianxu[0]) {
//                break;
//            }
//        }
//        if (i <)
//    }


void test_0() {
    vector<int> xianqu={1,2,4,5,3};
    vector<int> zhongxu={4,2,5,1,3};
    vector<int> rightView = solve(xianqu, zhongxu);
    printVector(rightView);
}

int main() {
    test_0();

    return 0;
}