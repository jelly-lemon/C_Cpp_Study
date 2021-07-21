/*
 * 给定一个字符串数组，再给定整数k，请返回出现次数前k名的字符串和对应的次数。
返回的答案应该按字符串出现频率由高到低排序。如果不同的字符串有相同出现频率，按字典序排序。
对于两个字符串，大小关系取决于两个字符串从左到右第一个不同字符的 ASCII 值的大小关系。
比如"ah1x"小于"ahb"，"231"<”32“
字符仅包含数字和字母

[要求]
如果字符串数组长度为N，时间复杂度请达到O(NlogK)
 */

/**
 * 大顶堆比较函数
 */
struct cmp {
    /**
     * 实现 lesss（即'<'运算符），前面的元素 < 后面的元素
     * 比较过程（个人理解）：从根节点开始比较，类似二分查找过程
     *
     * @param m1
     * @param m2
     * @return
     */
    bool operator()(map<string, int> m1, map<string, int> m2) {
        if (m1.begin()->second != m2.begin()->second) {
            int n1 = m1.begin()->second;
            int n2 = m2.begin()->second;
            return n1 < n2;
        } else {
            string s1 = m1.begin()->first;
            string s2 = m2.begin()->first;
            //
            // 【难点】字符串函数容易让人头晕，到底怎么返回？
            // 字典序越小，优先级越大，既 a > b
            //
            int n = strcmp(s1.c_str(), s2.c_str()); // strcmp 表示：s1
            return n > 0;
        }
    }
};

/**
 * 运行时间：26ms
超过68.71% 用C++提交的代码
占用内存：4324KB
超过8.77%用C++提交的代码
 *
 * return topK string
 * @param strings string字符串vector strings
 * @param k int整型 the k
 * @return string字符串vector<vector<>>
 */
vector<vector<string> > topKstrings(vector<string>& strings, int k) {
    // write code here
    unordered_map<string, int> hashTable;
    priority_queue<map<string, int>, vector<map<string, int>>, cmp> maxHeap;
    vector<vector<string>> r;

    for (auto &s:strings) {
        if (hashTable.find(s) == hashTable.end()) {
            hashTable[s] = 1;
        } else {
            hashTable[s]++;
        }
    }
    auto it = hashTable.begin();
    for(; it != hashTable.end(); it++) {
        map<string, int> m;
        m[it->first] = it->second;
        maxHeap.push(m);
    }

    for (int i = 0; i < k; i++) {
        if (!maxHeap.empty()) {
            vector<string> e;
            map<string, int> m = maxHeap.top();
            maxHeap.pop();
            e.push_back(m.begin()->first);
            e.push_back(to_string(m.begin()->second));
            r.push_back(e);
        } else {
            break;
        }
    }

    return r;
}