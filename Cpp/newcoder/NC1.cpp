/*
 * 以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。
（字符串长度不大于100000，保证字符串仅由'0'~'9'这10种字符组成）
 输入："1","99"
 返回值："100"
 */

/**
 * 运行时间：172ms
超过15.93%用C++提交的代码
占用内存：1464KB
超过46.18%用C++提交的代码
 */
string solve(string s, string t) {
    // write code here
    int len1 = s.size();
    int len2 = t.size();
    // 在短字符串前面补0，让两个字符串长度相等
    if (len1 > len2) {
        for (int i = 0; i < len1-len2; i++) {
            t = "0" + t;
        }
    } else if (len1 < len2) {
        for (int i = 0; i < len2-len1; i++) {
            s = "0" + s;
        }
    }
    len1 = s.size();
    int up = 0;    // 进位
    string sum;
    for (int i = len1-1; i >= 0; i--) {
        char c = '0';
        if ((s[i]-'0')+(t[i]-'0') >= 10) {
            if (up == 1) {
                c += (s[i]-'0')+(t[i]-'0') + 1;
                if (c - '0' >= 10) {
                    c -= 10;
                    up = 1;
                } else  {
                    up = 0;
                }
            } else {
                c += (s[i]-'0')+(t[i]-'0')-10;
                up = 1;
            }
        } else {
            if (up == 1) {
                if ((s[i]-'0')+(t[i]-'0') + 1 == 10) {
                    c = '0';
                    up = 1;
                } else {
                    c += (s[i]-'0')+(t[i]-'0') + 1;
                    up = 0;
                }
            } else {
                c += (s[i]-'0')+(t[i]-'0');
                up = 0;
            }
        }
        sum = c + sum;
    }
    if (up == 1) {
        sum = "1" + sum;
    }

    int i = 0;
    while (sum[i] == '0' && i < sum.size()) {
        i++;
    }
    if (i == sum.size()) {
        return "0";
    } else {
        return string(sum, i);
    }
}