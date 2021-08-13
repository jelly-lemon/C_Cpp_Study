/**
 * JZ48 不用加减乘除做加法
 *
 * 描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

 示例1
输入：1,2
返回值：3

 思考：负数呢？
 */


/**
    ^：异或

    运行时间：4ms
超过7.86% 用C++提交的代码
占用内存：612KB
超过15.29%用C++提交的代码
    */
int Add(int num1, int num2) {
    int result = 0;
    int carry = 0;
    do {
        // 按位异或，不带进位的加法
        result = num1 ^ num2;
        // 按位与并左移一位，加上进位
        carry = (num1 & num2) << 1;

        num1 = result;
        num2 = carry;

    } while(carry != 0); // 进位还没算进去

    return result;
}