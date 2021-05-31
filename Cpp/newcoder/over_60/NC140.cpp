/*
 * 给定一个数组，请你编写一个函数，返回该数组排序后的形式。
 * 备注：数组的长度不大于100000，数组中每个数的绝对值不超过10^9
 *
 * 输入：[5,2,3,1,4]
 * 返回值：[1,2,3,4,5]
 *
 */

/**
 * 快速排序
 *
 * 运行时间：54ms
超过73.56% 用C++提交的代码
占用内存：4316KB
超过39.60%用C++提交的代码
 */
vector<int> MySort(vector<int>& arr) {
    if (arr.size() == 0 or arr.size() == 1)
        return arr;

    QuickSort(arr, 0, arr.size());

    return arr;
}

void QuickSort(vector<int>& arr, int start, int end) {
    if (end - start > 1) {
        int index = QuickBase(arr, start, end);
        QuickSort(arr, start, index);
        QuickSort(arr, index+1, end);
    }
    // 【踩坑】 之前在 QuickSort 中有返回值 arr，直接导致超时，不清楚原因
}

int QuickBase(vector<int>& arr, int start, int end) {
    int len = end - start;
    int axis = start;
    int low, high;
    low = start, high = end-1;
    while (low < high) {
        // 【易错点】不能只用 >，要是两个数相等，无限交换
        while (arr[high] >= arr[axis] && low < high) {
            high--;
        }
        if (low < high) {
            int t = arr[high];
            arr[high] = arr[axis];
            arr[axis] = t;
            axis = high;
        }
        while (arr[low] <= arr[axis] && low < high) {
            low++;
        }
        if (low < high) {
            int t = arr[low];
            arr[low] = arr[axis];
            arr[axis] = t;
            axis = low;
        }
    }
    return axis;
}