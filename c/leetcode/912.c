#include<stdio.h>
#include <malloc.h>
#define N 4

void swap(int *a, int *b);
int* SelectionSort(int nums[], int numsSize);
int* sortArray(int* nums, int numsSize, int* returnSize);
int* copy(const int* nums, int numsSize);
int* QuickSort(int nums[], int numsSize);
int* MergerSort(int nums[], int numsSize);

/*
 * 912. 排序数组
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    return MergerSort(nums, numsSize);
}

/**
 * 选择排序，升序排序
 * 每次选择待排序数组中最小的数，放在已排序数组最后面
 * @param nums
 * @param numsSize
 * @return
 */
int* SelectionSort(int nums[], int numsSize) {
    int i, j;
    int min, t;
    int* returnNums = copy(nums, numsSize);

    //
    // i 可以理解成待进行选择最小值的数组
    // 最后只剩一个数，肯定是最大的，直接插入到已排序数组最后面
    //
    for (i = 0; i < numsSize - 1; i++) {
        //
        // 找最小值
        //
        min = returnNums[i];  // 默认第 1 个数为最小
        t = i;
        for (j = i + 1; j < numsSize; j++) {
            if (returnNums[j] < min) {
                min = returnNums[j];
                t = j;
            }
        }

        //
        // 放在已排序数组最后面
        //
        swap(&returnNums[i], &returnNums[t]);
    }

    return returnNums;
}

/**
 * 归并排序：归并两个有序的数组为一个有序数组
 *
 * @param nums
 * @param numsSize
 * @return
 */
int* MergerSort(int nums[], int numsSize) {
    //
    // 返回一个新的数组
    //
    int* returnNums = copy(nums, numsSize);

    //
    // 递归终止条件
    //
    if (numsSize <= 1) {
        return returnNums;
    }

    //
    // 分
    //
    int leftNum = numsSize / 2;
    int rightNum = numsSize - leftNum;
    int* left = MergerSort(nums, leftNum);
    int* right = MergerSort(nums + leftNum, rightNum);

    //
    // 合并
    //
    int i, j, k;
    i = j = 0;
    for (k = 0; k < numsSize; k++) {
        if (i >= leftNum && j < rightNum) {
            returnNums[k] = right[j];
            j++;
            continue;
        }
        if (i < leftNum && j >= rightNum) {
            returnNums[k] = left[i];
            i++;
            continue;
        }
        if (left[i] <= right[j]) {
            returnNums[k] = left[i];
            i++;
        } else {
            returnNums[k] = right[j];
            j++;
        }
    }

    return returnNums;
}

int* QuickSort(int nums[], int numsSize) {
    //
    // 递归终止条件
    //
    if (numsSize <= 1) {
        return nums;
    }

    int key, i, j;

    i = 0, j = numsSize - 1;
    key = nums[0];
    while (i < j) {
        //
        // j 找比 key 小的数
        //
        while (nums[j] >= key) {
            j--;
            if (j == i) {
                break;
            }
        }

        if (j == i) {
            break;
        }


        //
        // i 找比 key 大的数
        //
        while (nums[i] <= key) {
            i++;
            if (i == j) {
                break;
            }
        }

        if (i == j) {
            break;
        } else {
            swap(nums + i, nums + j);
        }
    }

    //
    // 把 key 放到中间
    //
    swap(nums, nums + i);

    //
    // 对左边进行快排
    //
    QuickSort(nums, i);


    //
    // 对右边进行快排
    //
    QuickSort(&nums[i + 1], numsSize - (i + 1));

    return nums;
}


/*
 * 交换两个数
 */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * 复制一个数组
 * @param nums
 * @param numsSize
 * @return
 */
int* copy(const int* nums, int numsSize) {
    int* returnNums = malloc(sizeof(int) * numsSize);
    int i;

    for (i = 0; i < numsSize; i++) {
        returnNums[i] = nums[i];
    }

    return returnNums;
}


int main(void) {

    int nums[] = {5, 2, 3, 1};

    //
    // 排序前
    //
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    //
    // 排序
    //
    int* p = MergerSort(nums, N);

    //
    // 排序后
    //
    for (i = 0; i < N; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");


    return 0;
}

