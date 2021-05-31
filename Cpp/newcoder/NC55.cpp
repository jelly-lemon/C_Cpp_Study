/*
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 输入：["abca","abc","abca","abc","abcc"]
 * 返回值："abc"
 *
 * 老糊涂了，最开始把题目理解成最长公共字串。
 */


/**
 * 思路 1：首先找出最短字符串长度，其次把所有字符串和第一个字符串从头开始挨个比较，
 * 最后，当比较出现不相等时，此时就是最大公共前缀。
 *
 * 运行时间：5ms
超过39.94% 用C++提交的代码
占用内存：376KB
超过84.27%用C++提交的代码
 */
string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
        return "";
    if (strs.size() == 1)
        return strs[0];

    // 找出最短字串长度
    int len = strs.size();
    int minLen = strs[0].size();
    for (int i = 1; i < len; i++) {
        if (strs[i].length() < minLen) {
            minLen = strs[i].length();
        }
    }

    int i, j;
    for (i = 0; i < minLen; i++) {
        for (j = 1; j < len; j++) {
            if (strs[0][i] != strs[j][i]) {
                break;
            }
        }
        if (j != len)
            break;
    }
    return strs[0].substr(0, i);
}