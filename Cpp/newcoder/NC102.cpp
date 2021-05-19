/*
 * 给定一棵二叉树以及这棵树上的两个节点 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。
 *
 * 输入：
 * [3,5,1,6,2,0,8,#,#,7,4],5,1
 *
 * 返回值：
 * 3
 */

/**
 * 运行时间：4ms
超过48.44%用C++提交的代码
占用内存：504KB
超过45.85%用C++提交的代码
 */
int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    // 按层遍历
    vector<int> arr;
    queue<TreeNode*> que;
    que.push(root);
    bool flag;
    if (root == NULL) {
        flag = false;
    } else {
        flag = true;
    }
    while (flag) {
        flag = false;
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* p = que.front();
            que.pop();
            if (p == NULL) {
                // 【易错点】按层遍历
                arr.push_back(-999);
                que.push(NULL);
                que.push(NULL);
            } else {
                arr.push_back(p->val);
                que.push(p->left);
                que.push(p->right);
                flag = true;
            }
        }
    }


    // 求 o1 和 o2 所在层次
    int len = arr.size();
    int level_1, level_2;
    int index_1, index_2;    // 从1计数
    for (int i = 0; i < len; i++) {
        if (o1 == arr[i]) {
            level_1 = log2(i+1);
            index_1 = i+1;
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        if (o2 == arr[i]) {
            level_2 = log2(i+1);
            index_2 = i+1;
        }
    }

    // 求 o1 和 o2 的最近公共祖先节点
    int p1, p2;
    p1 = index_1;
    p2 = index_2;
    // o1 在底层，o2 在高层
    if (level_1 > level_2) {
        for (int i = 0; i < level_1-level_2; i++) {
            p1 /= 2;
        }
        // 若 o2 是祖先节点
        if (p1 == p2) {
            return arr[p1-1];
        } else {
            // 两个节点分居两颗子树，祖先节点还在上面
            while (arr[p1-1] != arr[p2-1]) {
                p1 /= 2;
                p2 /= 2;
            }
            return arr[p1-1];
        }
    } else if (level_1 == level_2) {
        // 两个节点分居两颗子树，祖先节点还在上面
        while (arr[p1-1] != arr[p2-1]) {
            p1 /= 2;
            p2 /= 2;
        }
        return arr[p1-1];
    } else if (level_1 < level_2) {
        // o1 在高层，o2 在底层
        for (int i = 0; i < level_2-level_1; i++) {
            p2 /= 2;
        }
        // 若 o1 是祖先节点
        if (p1 == p2) {
            return arr[p1-1];
        } else {
            // 两个节点分居两颗子树，祖先节点还在上面
            while (arr[p1-1] != arr[p2-1]) {
                p1 /= 2;
                p2 /= 2;
            }
            return arr[p1-1];
        }
    }
    return -999;
}