/**
 *  连续子数组的最大和
 *
 * 描述
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n).

 示例1
输入：[1,-2,3,10,-4,7,2,-5]

 返回值：18

 说明：
输入的数组为{1,-2,3,10,—4,7,2,一5}，和最大的子数组为{3,10,一4,7,2}，因此输出为该子数组的和 18。
 */

/**
 * 思路 1：动态规划
 *
    运行时间：3ms
超过29.83% 用C++提交的代码
占用内存：512KB
超过22.17%用C++提交的代码
*/
int FindGreatestSumOfSubArray(vector<int> array) {
    int *p = new int[array.size()+1];
    p[0] = 0;

    //
    // i 表示以 array[i] 作为子数组最后一个数字时，求和
    //
    for (int i = 1; i <= array.size(); i++) {
        if (array[i-1] >= 0) {
            if (p[i-1] > 0) {
                p[i] = p[i-1] + array[i-1];
            } else {
                p[i] = array[i-1];
            }
        } else {
            //
            // 只有当负数的绝对值大于前面和时，才不添加到子数组
            //
            if (p[i-1] <= -array[i-1]) {
                p[i] = array[i-1];
            } else {
                p[i] = p[i-1] + array[i-1];
            }
        }
    }

    //
    // 【易错点】数组可能全为负，max = p[0] = 0 可能就是最大值了
    //
    int max = p[1];
    for (int i = 2; i <= array.size(); i++) {
        if (p[i] > max) {
            max = p[i];
        }
    }

    return max;
}