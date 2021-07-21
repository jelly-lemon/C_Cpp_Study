/**
 * 运行时间：2ms
超过86.83% 用C++提交的代码
占用内存：380KB
超过59.10%用C++提交的代码

 思路 1：直接使用库函数
 */
int sqrt(int x) {
    // write code here
    return (int)sqrtf(x);
}

/**
 * 运行时间：2ms
超过86.83% 用C++提交的代码
占用内存：356KB
超过87.71%用C++提交的代码

 * 思路 2：如果是完全根号数，则该数值是顺序基数累加，同时该数的平方跟就是奇数的个数
 * 1+3+5+7=16, 根号16 = 4
 */
int sqrt(int x) {
    if (x < 1)
        return 0;

    int start = 1;
    int sum = 0;
    int rt = 0;

    sum += start;
    while (x >= sum) {
        rt++;
        start += 2;
        sum += start;
    }

    return rt;
}