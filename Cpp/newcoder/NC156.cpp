/*
 * 给定一个整型数组 arrarr 和一个整数 k(k>1)k(k>1)。
已知 arrarr 中只有 1 个数出现一次，其他的数都出现 kk 次。
请返回只出现了 1 次的数。

 输入：
 [5,4,1,1,5,1,5],3
 输出：
 4

 个人感觉：不看答案根本不知道还能用位运算

 要是 k 是偶数，就可以用连续位运算求得只出现一次的元素。
 但若 k 是基数，就行不通。
 */

/**
 * 思路 1：用 hash 表，时间复杂度 O(n)
 *
 * 运行时间：4ms
超过87.67% 用C++提交的代码
占用内存：612KB
超过46.03%用C++提交的代码
 */
int foundOnceNumber(vector<int>& arr, int k) {
    unordered_map<int, int> hashTable;

    // 统计每一个数字出现的次数，O(n)
    for (int &a : arr) {
        if (hashTable.find(a) == hashTable.end()) {
            hashTable[a] = 1;
        } else {
            hashTable[a]++;
        }
    }

    // 找出只出现一次的数字，O(n)
    for (pair<int, int> p : hashTable) {
        if (p.second == 1)
            return p.first;
    }
    return -1;
}

