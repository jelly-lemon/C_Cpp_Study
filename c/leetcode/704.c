#include <stdio.h>

int binarySearch(const int* nums, int numsSize, int target);
int search(int* nums, int numsSize, int target);

/**
 * 二分查找、折半查找
 *
 * @param nums 数组
 * @param numsSize 数组长度
 * @param target 查找目标值
 * @return 找到返回元素下标，没找到返回 -1
 */
int binarySearch(const int* nums, int numsSize, int target) {
    int i, j;

    i = 0, j = numsSize - 1;    // i，j 分别表示当前首查找位置、当前尾查找位置
    // 查找结束条件为 i > j
    while (i <= j ) {
        if (target == nums[(i+j)/2]) {
            return (i+j)/2;
        // 当目标值小于数组中间元素，则说明在左边
        } else if (target < nums[(i+j)/2]) {
            // 【易错点】新尾查找位置应该应该位于中间点左边一位，因为中间点已经比对过了，不是目标值。
            j = (i+j)/2 - 1;
        } else {
            i = (i+j)/2 + 1;
        }
    }

    return -1;
}

int search(int* nums, int numsSize, int target){
    return binarySearch(nums, numsSize, target);
}

int main(void) {

    int nums[] = {-1,0,3,5,9,12};
    int target = 9;
    int pos = search(nums, 6, target);
    printf("%d\n", pos);

    return 0;
}