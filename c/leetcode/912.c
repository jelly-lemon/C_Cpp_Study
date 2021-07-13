#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void swap(int *a, int *b);
int* sortArray(int* nums, int numsSize, int* returnSize);
int* quickSort_1(int *nums, int numsSize);
void printNum(int nums[], int n);

/*
 * 912. 排序数组
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    return NULL;
}

void printNum(int nums[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * 冒泡排序
 */
int *bubbleSort(int nums[], int numsSize) {
    int i, j;
    for (i = 0; i < numsSize-1; i++) {
        //
        // 一趟冒泡，数组可以分成两部分，已冒泡和未冒泡部分
        // 每一趟冒泡操作，都是两两交换
        //
        for (j = 1; j < numsSize-i; j++) {
            if(nums[j-1] > nums[j]) {
                swap(&nums[j-1], &nums[j]);
            }
        }
        printNum(nums, numsSize);
    }

    return nums;
}

/**
 * 选择排序
 * 思想：将数组看作两个部分：已排序和未排序部分
 * 每次选择待排序数组中最小的数，放在已排序数组最后面
 */
int* selectSort(int *nums, int numsSize) {
    int iLeft = 0, iRight = 0;
    while (iLeft < numsSize) {
        //
        // 找未排序部分最小的数
        //
        int iMin = iRight;
        for (int i = iRight+1; i < numsSize; i++) {
            if(nums[i] < nums[iMin]) {
                iMin = i;
            }
        }

        //
        // 插入到已排序部分末尾
        //
        swap(&nums[iLeft], &nums[iMin]);
        iLeft++, iRight++;
        printNum(nums, numsSize);
    }

    return nums;
}


/**
 * 归并排序：归并两个有序的数组为一个有序数组
 * 缺点：每一次调用，都会创建一个子数组，当数组长度很大时，将会递归调用多次，
 * 导致占用空间过多
 */
int* mergeSort_1(int *nums, int numsSize) {
    if (numsSize <= 1) {
        return nums;
    }

    //
    // 创建一个新数组
    //
    int newArr[numsSize];
    memcpy(newArr, nums, sizeof(int)*numsSize);

    //
    // 分：二分数组
    //
    int leftNum = numsSize / 2;
    int rightNum = numsSize - leftNum;
    mergeSort_1(newArr, leftNum);
    printNum(newArr, leftNum);
    mergeSort_1(newArr + leftNum, rightNum);
    printNum(newArr+leftNum, rightNum);

    //
    // 【难点，编程极易出错】合：合并两个有序的数组
    //
    int iLeft = 0, iRight = leftNum;
    for (int k = 0; k < numsSize; k++) {
        if (iLeft == leftNum) {
            nums[k] = newArr[iRight++];
        } else if (iRight == numsSize) {
            nums[k] = newArr[iLeft++];
        } else {
            if (newArr[iLeft] <= newArr[iRight]) {
                nums[k] = newArr[iLeft++];
            } else{
                nums[k] = newArr[iRight++];
            }
        }
    }
    printNum(nums, numsSize);

    return nums;
}

/**
 * 归并排序
 */
int* mergeSort_2(int *nums, int numsSize) {
    if (numsSize <= 1) {
        return nums;
    }

    //
    // 创建一个新数组
    //
    int newArr[numsSize];
    memcpy(newArr, nums, sizeof(int)*numsSize);

    //
    // 分：二分数组
    //
    int leftNum = numsSize / 2;
    int rightNum = numsSize - leftNum;
    mergeSort_1(newArr, leftNum);
    printNum(newArr, leftNum);
    mergeSort_1(newArr + leftNum, rightNum);
    printNum(newArr+leftNum, rightNum);

    //
    // 合：第二种写法
    //
    int i = 0, j = leftNum;
    int k = 0;
    while (i < leftNum && j < numsSize) {
        if (newArr[i] <= newArr[j]) {
            nums[k++] = newArr[i++];
        } else {
            nums[k++] = newArr[j++];
        }
    }
    while (i < leftNum) {
        nums[k++] = newArr[i++];
    }
    while (j < numsSize) {
        nums[k++] = newArr[j++];
    }

    return nums;
}



/**
 * 快速排序
 */
int* quickSort_1(int *nums, int numsSize) {
    //
    // 递归终止条件
    //
    if (numsSize <= 1) {
        return nums;
    }

    //
    // 随机选取中轴
    //
    int mid = rand() % (numsSize-1);
    printf("mid: %d\n", mid);

    //
    // 将中轴交换到正确位置
    // 思路：分别从后往前看、从前往后看。
    // 从后往前看时，没有需要交换的数，到中轴就停止！从前往后看同理。
    //
    int i = 0, j = numsSize-1;
    while (i < j) {
        while (mid < j && nums[j] >= nums[mid]) {
            j--;
        }
        if (j != mid && nums[j] < nums[mid]) {
            swap(&nums[j], &nums[mid]);
            mid = j;
        }
        while (i < mid && nums[i] <= nums[mid]) {
            i++;
        }
        if (i != mid && nums[i] > numsSize) {
            swap(&nums[i], &nums[mid]);
            mid = i;
        }
    }
    printNum(nums, numsSize);

    //
    // 对中轴元素左右两边子数组进行排序
    // 【易错点】中轴元素不要算进去了
    //
    quickSort_1(nums, mid);
    quickSort_1(nums + (mid + 1), numsSize - (mid + 1));

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
 * 测试
 */
void test_0() {
    int nums[] = {23, 2, 11, 6, 22, 34, 3, 61, 15, 11, 15, 37, 40, 44};
//    int nums[] = {3, 2, 5, 1, 7};

    int N = sizeof(nums)/ sizeof(int);

    // 排序前
    printf("before: ");
    printNum(nums, N);

    // 排序
    bubbleSort(nums, N);

    // 排序后
    printf("after: ");
    printNum(nums, N);
}


int main(void) {

    test_0();


    return 0;
}

