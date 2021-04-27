/*
 运行时间：3ms
超过10.80%用C++提交的代码
占用内存：392KB
超过33.92%用C++提交的代码
 */
string solve(string str) {
    // write code here
    int n = str.length();
    int i;
    for (i = 0; i < n/2; i++) {
        char t = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = t;
    }
    return str;
}