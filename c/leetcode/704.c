#include <stdio.h>

int binarySearch(const int* nums, int numsSize, int target);
int search(int* nums, int numsSize, int target);

/**
 * 二分查找、折半查找
 * @param nums
 * @param numsSize
 * @param target
 * @return
 */
int binarySearch(const int* nums, int numsSize, int target) {
    int i, j;

    i = 0, j = numsSize - 1;
    while (i <= j ) {
        if (target < nums[(i+j)/2]) {
            j = (i+j)/2 - 1;
        } else if (target == nums[(i+j)/2]) {
            return (i+j)/2;
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