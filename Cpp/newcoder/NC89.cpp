/*
 * 对于一个给定的字符串，我们需要在线性(也就是O(n))的时间里对它做一些变形。
 * 首先这个字符串中包含着一些空格，就像"Hello World"一样，
 * 然后我们要做的是把着个字符串中由空格隔开的单词反序，
 * 同时反转每个字符的大小写。比如"Hello World"变形后就变成了"wORLD hELLO"。
 *
 * 输入：
 * 给定一个字符串s以及它的长度n(1≤n≤500)
 *
 * 输出：
 * 请返回变形后的字符串。题目保证给定的字符串均由大小写字母和空格构成。
 *
 * 输入：
 * "This is a sample",16
 *
 * 输出：
 * "SAMPLE A IS tHIS"
 */



/**
 * 思路 1：首先翻转整个字符串，其次按空格翻转每个单词，最后大小写转换
 *
 * 运行时间：3ms
超过10.57% 用C++提交的代码
占用内存：484KB
超过68.27%用C++提交的代码
 */
string trans(string s, int n) {
// write code here
// 第一次翻转
    reverse(s, 0, n - 1);

    int low, high;
    low = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            high = i - 1;
            reverse(s, low, high);
            low = i + 1;
        }
    }
    reverse(s, low, n - 1);

    for (int i = 0; i < n; i++) {
        if ('a' <= s[i] and s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
            continue;
        }
        if ('A' <= s[i] and s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
            continue;
        }
    }

    return s;
}

void reverse(string &s, int low, int high) {
    while (low < high) {
        int t = s[low];
        s[low] = s[high];
        s[high] = t;
        low++;
        high--;
    }
}