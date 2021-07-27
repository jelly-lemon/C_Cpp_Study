/**
* 描述
给出两个字符串 S 和 T，要求在O(n)的时间复杂度内在 S 中找出最短的包含 T 中所有字符的子串。
例如：
S="XDOYEZODEYXNZ"
T="XYZ"
找出的最短子串为""YXNZ".

注意：
如果 S 中没有包含 T 中所有字符的子串，返回空字符串 “”；
满足条件的子串可能有很多，但是题目保证满足条件的最短的子串唯一。


 示例1
输入：
"XDOYEZODEYXNZ","XYZ"
返回值：
"YXNZ"
*/

/**
     *运行时间：3ms
超过77.35% 用C++提交的代码
占用内存：512KB
超过30.81%用C++提交的代码

 【思路】滑动窗口，很难，以前完全没接触这类题型
     */
string minWindow(string S, string T) {
    // write code here
    string minStr;
    int left, right, count, minLen;
    char c;
    left = right = 0;
    count = 0;
    minLen = INT32_MAX;
    unordered_map<char, int> window, target;
    for (auto &ch:T) {
        target[ch]++;
    }

    // 右扩
    while(right < S.size()) {
        c = S[right++];
        if(target.count(c)) {
            window[c]++;
            if(window[c] == target[c]) {
                count++;
            }
        }
        // 左缩
        while(count == target.size()) {
            if (right-left < minLen) {
                minLen = right - left;
                minStr = S.substr(left, minLen);
            }
            c = S[left++];
            if (target.count(c)) {
                if (window[c] == target[c]) {
                    count--;
                }
                window[c]--;
            }
        }
    }

    return minStr;
}