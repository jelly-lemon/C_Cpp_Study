/**
 * 描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。

示例1
输入：3
返回值：4
 */

/**
 * 递归公式：
 * f(n) = 1 + f(n-1) + ... + f(1)
 * 第一个 1 表示：一次跳 n 阶
 *
    运行时间：4ms
超过12.65% 用C++提交的代码
占用内存：604KB
超过57.45%用C++提交的代码
*/
int jumpFloorII(int number) {
    int *p = new int[number+1];
    p[0] = 0;
    p[1] = 1;

    for (int i = 2; i <= number; i++) {
        p[i] = 1;
        for (int j = i-1; j >= 1; j--) {
            p[i] += p[j];
        }
    }

    return p[number];
}