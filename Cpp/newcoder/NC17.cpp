/*
对于一个字符串，请设计一个高效算法，计算其中最长回文子串的长度。
给定字符串 A 以及它的长度 n，请返回最长回文子串的长度。

 测试用例：
 "abc1234321ab",12 --> 7，即 1234321
 "abc",3 --> 1，即单独的一个字符

 思路 1：
 枚举法，挨个判断字串是不是回文串，显然很低效

 */
#include <iostream>
#include <string>
using namespace std;

/**
 * 判断是否是回文串
 */
bool isPalindrome(string A) {
    if (A.empty())
        return false;
    if (A.length() == 1) {
        return true;
    }

    int i, j;
    i = 0;
    j = A.length() - 1;
    while (i < j) {
        if (A[i] != A[j])
            return false;
        i++, j--;
    }
    return true;
}


/**
 * 递归的基础上，优化了递归进入条件，节省了很多不必要的开销，但仍然超时
 */
int getLongestPalindrome(string A, int n) {
    if (A.empty()) return 0;

    if (isPalindrome(A))
        return A.length();
    else {
        int maxLen = 0;
        for (int i = 0; i < A.length(); i++) {
            for (int j = A.length()-1; j > i; j--) {
                if (i == 0 && j == A.length()-1)
                    continue;
                int len;
                if (A[i] == A[j] && A[i+1] == A[j-1]) {
                    string s(A, i, j-i+1);
                    len = getLongestPalindrome(s, s.length());
                    if (len > maxLen)
                        maxLen = len;
                }
            }
        }
        return maxLen;
    }
}

/**
 * 思路 1：枚举法
 *
 * 运行时间：45ms
超过5.07%用C++提交的代码
占用内存：376KB
超过93.20%用C++提交的代码
 */
int getLongestPalindrome_3(string A, int n) {
    if (A.empty())
        return 0;
    if (A.length() == 1)
        return 1;

    int maxLen = 0;

    for (int i = 0; i < A.length(); i++) {
        for (int j = A.length()-1; j > i; j--) {
            string s(A, i, j-i+1);
            if (isPalindrome(s))
                if (s.length() > maxLen)
                    maxLen = s.length();
        }
    }

    return maxLen;
}

/**
 * 思路 2：动态规划
 *
 * TODO 待完成
 */
int getLongestPalindrome_4(string A, int n) {
    if (n == 0)
        return 0;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int start = (i-1) - dp[i-1] - 1;    // 开始下标
        if (start < 0) {
            dp[i] = dp[i-1];
            continue;
        }

        int len = dp[i-1] + 2;
        string s(A, start, len);
        if (!isPalindrome(s)) {
            dp[i] = dp[i-1];
        } else {
            if (len > dp[i-1]) {
                dp[i] = len;
            } else {
                dp[i] = dp[i-1];
            }
        }
    }

    return dp[n];
}

/**
 * 递归写法，超时
 */
int getLongestPalindrome_2(string A, int n) {
    if (A.empty()) return 0;

    if (isPalindrome(A))
        return A.length();
    else {
        string s1(A, 0, n-1);
        string s2(A, 1, n-1);
        int n1 = getLongestPalindrome_2(s1, n - 1);
        int n2 = getLongestPalindrome_2(s2, n - 1);
        return n1 > n2 ? n1 : n2;
    }
}

void test_0() {
    string s("abcd");
    if (isPalindrome(s)) {
        cout << s << " yes" << endl;
    } else {
        cout << s << " no" << endl;
    }
    string s1("abc");
    if (isPalindrome(s1)) {
        cout << s1 << " yes" << endl;
    } else {
        cout << s1 << " no" << endl;
    }
    string s2("aba");
    if (isPalindrome(s2)) {
        cout << s2 << " yes" << endl;
    } else {
        cout << s2 << " no" << endl;
    }
    string s3("abba");
    if (isPalindrome(s3)) {
        cout << s3 << " yes" << endl;
    } else {
        cout << s3 << " no" << endl;
    }
}

void test_1( ) {
    int n, maxLen;
    string s;

    s = "12aba12";
    n = 7;
    maxLen = getLongestPalindrome_2(s, n);
    cout << maxLen << endl;

    // 运行时间很长
    s = "12456789abcdefggfedcba111111";
    n = s.length();
    maxLen = getLongestPalindrome_2(s, n);
    cout << maxLen << endl;

    s = "abad";
    n = s.length();
    maxLen = getLongestPalindrome_2(s, n);
    cout << maxLen << endl;
}

void test_2() {
    int n, maxLen;
    string s;

    s = "12aba12";
    n = 7;
    maxLen = getLongestPalindrome(s, n);
    cout << maxLen << endl;

    // 运行时间很长
    s = "12456789abcdefggfedcba111111";
    n = s.length();
    maxLen = getLongestPalindrome(s, n);
    cout << maxLen << endl;

    s = "abad";
    n = s.length();
    maxLen = getLongestPalindrome(s, n);
    cout << maxLen << endl;

    s = "adbjlkabdjblkcxzjlbklkfbnlknabcdefgfedcbaofihbozobanaenknbqrkln";
    n = s.length();
    maxLen = getLongestPalindrome(s, n);
    cout << maxLen << endl;

    s = "";
    n = s.length();
    maxLen = getLongestPalindrome(s, n);
    cout << maxLen << endl;


    s = "aabaA";
    n = s.length();
    maxLen = getLongestPalindrome(s, n);
    cout << maxLen << endl;
}

void test_3() {
    int n, maxLen;
    string s;

    s = "12aba12";
    n = 7;
    maxLen = getLongestPalindrome_3(s, n);
    cout << maxLen << endl;

    // 运行时间很长
    s = "12456789abcdefggfedcba111111";
    n = s.length();
    maxLen = getLongestPalindrome_3(s, n);
    cout << maxLen << endl;

    s = "abad";
    n = s.length();
    maxLen = getLongestPalindrome_3(s, n);
    cout << maxLen << endl;

    s = "adbjlkabdjblkcxzjlbklkfbnlknabcdefgfedcbaofihbozobanaenknbqrkln";
    n = s.length();
    maxLen = getLongestPalindrome_3(s, n);
    cout << maxLen << endl;

    s = "";
    n = s.length();
    maxLen = getLongestPalindrome_3(s, n);
    cout << maxLen << endl;


    s = "aabaA";
    n = s.length();
    maxLen = getLongestPalindrome_3(s, n);
    cout << maxLen << endl;
}

int main() {
    test_3();

    return 0;
}