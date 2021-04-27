/* kmp 算法
 给你一个非空模板串S，一个文本串T，问S在T中出现了多少次
 */

/*
 运行时间：43ms
超过29.90%用C++提交的代码
占用内存：732KB
超过97.64%用C++提交的代码
 */
int kmp(string S, string T) {
    int len1 = S.length();
    int len2 = T.length();
    int i = 0;
    int count = 0;
    for (i = 0; i < len2 - len1 + 1; i++) {
        string s1(T, i, len1);
        if (S == s1) {
            count++;
        }
    }
    return count;
}