/**
 * JZ6 旋转数组的最小数字
 *
 * 描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
NOTE：给出的所有元素都大于0，若数组大小为 0，请返回 0。

示例1
输入：[3,4,5,1,2]
返回值：1
 */

/**
 * 思路 1：直接 for 循环查找
 *
* 运行时间：7ms
超过95.02% 用C++提交的代码
占用内存：652KB
超过42.60%用C++提交的代码
*/
int minNumberInRotateArray(vector<int> rotateArray) {
    int min = rotateArray[0];

    for (int &n:rotateArray) {
        if (n < min) {
            min = n;
        }
    }

    return min;
}

/**
 * 思路 2：二分查找
 */
int minNumberInRotateArray(vector<int> rotateArray) {

}