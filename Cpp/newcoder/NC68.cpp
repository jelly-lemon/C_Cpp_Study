/**
 * 描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。


示例1
输入：2
返回值：2

示例2
输入：7
返回值：21

 8.12：腾讯一面让我做的算法题
 */

/**
 *
 * 思路 1：递归写法，时间复杂度 O(2^n)
 *
 运行时间：297ms
超过31.94%用C++提交的代码
占用内存：504KB
超过69.76%用C++提交的代码
 */
int jumpFloor(int number) {
    int count = 0;
    if (number == 1) {
        return 1;
    } else if (number == 2) {
        return 2;
    } else if (number <= 0) {
        return 0;
    } else {
        count = jumpFloor(number - 1) + jumpFloor(number - 2);
        return count;
    }
}

/**
 * 思路 2：动态规划
 *
    运行时间：4ms
超过40.89% 用C++提交的代码
占用内存：608KB
超过52.72%用C++提交的代码
    */
int jumpFloor(int number) {
    int *p = new int[number+1];

    //
    // 【易错点】要初始化到 p[2]，n = 2 时有两种
    //
    p[0] = 0;
    p[1] = 1;
    p[2] = 2;

    // 【易错点】i 代表台阶数
    for (int i = 3; i <= number; i++) {
        p[i] = p[i-1] + p[i-2];
    }

    return p[number];
}