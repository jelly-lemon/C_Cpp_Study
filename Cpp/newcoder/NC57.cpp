/*
 运行时间：3ms
超过51.48%用C++提交的代码
占用内存：352KB
超过96.82%用C++提交的代码
 */
int reverse(int x) {
    // write code here
    int count = 0;
    bool isPos = x > 0 ? true : false;
    int n = x;
    while(n) {
        count++;
        n /= 10;
    }
    n = x;
    long long r = 0;
    int max = pow(2, 31) - 1;
    while (n) {
        int i = abs(n % 10);
        n /= 10;
        r += i * pow(10, count-1);
        if (r > max)
            return 0;
        count--;
    }

    return isPos ? (int)r : -(int)r;
}