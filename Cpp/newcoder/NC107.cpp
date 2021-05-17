/* 山峰元素是指其值大于或等于左右相邻值的元素。
 * 给定一个输入数组nums，任意两个相邻元素值不相等，
 * 数组可能包含多个山峰。找到索引最大的那个山峰元素并返回其索引。
假设 nums[-1] = nums[n] = -∞。

 【易错点】容易把题目错看作找到最大山峰元素
 *
 */

/**
 * 暴力法
 *
 * 运行时间：3ms
超过21.79%用C++提交的代码
占用内存：376KB
超过68.75%用C++提交的代码
 */
int solve(int* a, int aLen) {
    int i_max = 0;
    for (int i = 1; i < aLen-1; i++) {
        if (a[i-1] < a[i] and a[i] > a[i+1]) {
            i_max = i;
        }
    }
    if (a[aLen-1] > a[aLen-2]) {
        i_max = aLen-1;
    }
    return i_max;
}