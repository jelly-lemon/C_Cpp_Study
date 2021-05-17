


/**
 * 暴力法
 *
 * 运行时间：12ms
超过6.48%用C++提交的代码
占用内存：528KB
超过25.19%用C++提交的代码
 */
int search(vector<int>& nums, int target) {
    int i = 0;
    for (int &a : nums) {
        if (a == target) {
            return i;
        }
        i++;
    }

    return -1;
}

