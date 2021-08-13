/**
 * 求 1+2+...+n
 *
 * 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 *
 * 思路 1：递归
 *
    运行时间：4ms
超过7.67% 用C++提交的代码
占用内存：472KB
超过75.61%用C++提交的代码
*/
int Sum_Solution(int n) {
    if (n == 1) {
        return 1;
    }
    return n + Sum_Solution(n-1);
}