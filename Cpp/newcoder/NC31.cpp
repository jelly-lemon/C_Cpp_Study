/*
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)
 * 中找到第一个只出现一次的字符,
 * 并返回它的位置,
 * 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
 *
 * "google"
 * 4
 */


/*
 * 运行时间：3ms
超过52.53%用C++提交的代码
占用内存：508KB
超过40.53%用C++提交的代码
 */
int FirstNotRepeatingChar(string str) {
    int count[52] = {0};
    int p = 0;
    for (char &c : str) {
        if ('a' <= c && c <= 'z') {
            // 第一次出现
            count[c - 'a']++;
        } else {
            count[c - 'A' + 26]++;
        }
    }
    int i = 0;
    for (char &c : str) {
        if ('a' <= c && c <= 'z') {
            if (count[c-'a'] == 1) {
                return i;
            }
        } else {
            if (count[c-'A'+26] == 1) {
                return i;
            }
        }
        i++;
    }
    return -1;
}