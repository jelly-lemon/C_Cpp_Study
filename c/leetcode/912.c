#include<stdio.h>
#include <malloc.h>

void swap(int *a, int *b);
int* SelectionSort(int nums[], int numsSize);
int* sortArray(int* nums, int numsSize, int* returnSize);
int* copy(const int* nums, int numsSize);
int* QuickSort(int nums[], int numsSize);
int* MergerSort(int nums[], int numsSize);

void printNum(int nums[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

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

/**
 * 快速排序，写法 1。fixme 此算法有问题
 * 具体思路：
 * 中轴元素先不动。先交换：前大 <--> 后小。
 *
 * @param nums 数组
 * @param numsSize 数组大小
 */
int* QuickSort(int nums[], int numsSize) {
    // 递归终止条件
    if (numsSize <= 1) {
        return nums;
    }

    // 中轴元素的值，前下标，后下标
    int midValue, i, j;

    i = 0, j = numsSize - 1;
    midValue = nums[0];
    while (i < j) {
        // j 找比中轴元素小的数，找到就跳出 while
        while (nums[j] >= midValue) {
            j--;
            if (j == i) {
                break;
            }
        }
        if (j == i) {
            break;
        }

        // i 找比中轴元素大的数，找到就跳出 while
        while (nums[i] <= midValue) {
            i++;
            if (i == j) {
                break;
            }
        }

        // 判断是否遍历完毕
        if (i == j) {
            break;
        } else {
            // 【易错点】进行交换的是：一个比中轴大的数，一个是比中轴小的数，不是和中轴进行交换
            swap(nums + i, nums + j);
        }
    }

    // 前面大小元素交换完了，最后才把中轴元素放到正确的位置上
    // 把中轴元素放到中间，此时 i == j
    swap(nums, nums + i);

    for (int k = 0; k < i; k++) {
        printf("%d ", nums[k]);
    }
    printf("_%d_ ", nums[i]);
    for (int k = i+1; k < numsSize; k++) {
        printf("%d ", nums[k]);
    }
    printf("\n");

    // 对左边进行快排
    QuickSort(nums, i);

    // 对右边进行快排
    QuickSort(&nums[i + 1], numsSize - (i + 1));

    return nums;
}


/**
 * 交换两个数
 */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * 复制一个数组
 */
int* copy(const int* nums, int numsSize) {
    int* returnNums = malloc(sizeof(int) * numsSize);
    int i;

    for (i = 0; i < numsSize; i++) {
        returnNums[i] = nums[i];
    }

    return returnNums;
}



/**
 * 测试快排
 */
void test_0() {
    int nums[] = {23, 2, 11, 6, 22, 34, 3, 61, 15, 11, 15, 37, 40, 44};
    int N = sizeof(nums)/ sizeof(int);

    // 排序前
    printf("before: ");
    printNum(nums, N);

    // 排序
    int* p = QuickSort(nums, N);

    // 排序后
    printf("after: ");
    printNum(nums, N);
}


int main(void) {

    test_0();


    return 0;
}

