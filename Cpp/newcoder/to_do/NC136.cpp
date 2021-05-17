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
 */

/**
 * 思路 1：恢复二叉树，按层遍历，取每一层最末尾的元素
 * 【难点】如何恢复二叉树？二叉树怎么存？
 */


/**
 * 思路 2：递归
 */
vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // TODO
        vector<int> r;
        if (xianxu.size() == 0)
            return r;

        int i;
        for (i = 0; i < zhongxu.size(); i++) {
            if (zhongxu[i] == xianxu[0]) {
                break;
            }
        }
        if (i <)
    }