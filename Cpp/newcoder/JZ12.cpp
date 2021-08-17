/*
 JZ12 数值的整数次方

 描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0。不得使用库函数，同时不需要考虑大数问题，也不用考虑小数点后面0的位数。

示例1
输入：2.00000,3
返回值：8.00000

 示例2
输入：2.10000,3
返回值：9.26100

 示例3
输入：2.00000,-2
返回值：0.25000
说明：
2的-2次方等于1/4=0.25
 */

/**
    运行时间：4ms
超过10.03% 用C++提交的代码
占用内存：724KB
超过14.76%用C++提交的代码
*/
double Power(double base, int exponent) {
    if (base == 0) {
        return 0;
    }
    if (exponent == 0) {
        return 1;
    }


    // 【易错点】特别容易考虑不到 exponent 为负的情况
    double rt = base;
    int times = abs(exponent);
    for (int i = 1; i < times; i++) {
        rt *= base;
    }
    if (exponent < 0) {
        rt = 1/rt;
    }

    return rt;
}