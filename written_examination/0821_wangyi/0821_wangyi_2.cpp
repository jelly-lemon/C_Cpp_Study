/**
 *
 *
计算 K 位

 AC

Si = Si-1 + Li + reverse(invert(Si-1))


 L1 = 'a'
 L2 = 'b'
 ...

 reverse 表示反转字符串

 invert 表示镜像翻转字符
 如 'a' -> 'z', 'z' -> 'a'

 */
string invert(string s) {
    string newStr;
    for (auto &c:s) {
        char t = 'z' - (c - 'a');
        newStr += t;
    }

    return newStr;
}

string getStr(int i) {
    if (i <= 0) {
        return "";
    } if (i == 1) {
        return "a";
    }

    string si_1 = getStr(i-1);
    string invertedStr = invert(si_1);
    string reversedStr = invertedStr;
    reverse(reversedStr.begin(), reversedStr.end());
    char Li = 'a' + i-1;
    return si_1 + Li + reversedStr;
}

char findKthBit(int n, int k) {
    // write code here
    string s = getStr(n);
    return s[k-1];
}