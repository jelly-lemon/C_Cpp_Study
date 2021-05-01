/*
 给定一个数组arr，返回子数组的最大累加和
例如，arr = [1, -2, 3, 5, -2, 6, -1]，所有子数组中，[3, 5, -2, 6]可以累加出最大的和12，所以返回12.
题目保证没有全为负数的数据
[要求]
时间复杂度为O(n)O(n)，空间复杂度为O(1)O(1)
 */

/*
 * 暴力法
 超时
 */
int maxsumofSubarray(vector<int>& arr) {
    // write code here

    int max = 0;
    int curVal = 0;
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            continue;
        }
        curVal = arr[i];
        for (int j = i+1; j < len; j++) {
            if(curVal+arr[j] <= arr[j]) {
                break;
            } else {
                curVal += arr[j];
                if (max < curVal) {
                    max = curVal;
                }
            }
        }
    }
    return max;
}