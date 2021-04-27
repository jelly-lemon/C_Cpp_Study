/*
 * 缺失数字
 从0,1,2,...,n这n+1个数中选择n个数，找出这n个数中缺失的那个数，要求O(n)尽可能小。
 */

/*
 运行时间：13ms
超过1.48%用C++提交的代码
占用内存：756KB
超过2.06%用C++提交的代码
 */
int solve(vector<int>& a) {
    // write code here
    int len = a.size();
    int i;
    if (len <= 0)
        return -1;
    for(i = 0; i < len; i++) {
        if (a[i] != i)
            return i;
    }
    return i;
}