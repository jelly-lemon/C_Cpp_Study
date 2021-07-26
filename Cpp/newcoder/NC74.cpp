/**
 * 描述
统计一个数字在升序数组中出现的次数。

 示例1
输入：
[1,2,3,3,3,3,4,5],3

 返回值：4
 */

/**
 * 运行时间：2ms
超过73.46% 用C++提交的代码
占用内存：536KB
超过20.06%用C++提交的代码

 思路：二分找到某个元素，然后前后查找
 时间复杂度：O(n)
 */
int GetNumberOfK(vector<int> data ,int k) {
    int low = 0;
    int high = data.size() - 1;
    int mid;
    int count = 0;

    while (low <= high) {
        mid = (low + high)/2;
        if (data[mid] == k) {
            count++;
            break;
        } else if (data[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (low > high){
        return count;
    }

    int i = mid - 1;
    while (data[i--] == data[mid]) {
        count++;
    }

    i = mid + 1;
    while (data[i++] == data[mid]) {
        count++;
    }

    return count;
}

int getFirst(vector<int> data ,int k) {
    int low = 0;
    int high = data.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high)/2;
        if (data[mid] == k) {
            first = mid;
            low = 0;
            high = first-1;
        } else if (data[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return first;
}

int getLast(vector<int> data ,int k) {
    int low = 0;
    int high = data.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high)/2;
        if (data[mid] == k) {
            last = mid;
            low = last+1;
            high = data.size() - 1;
        } else if (data[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return last;
}

/**
 * 思路 2：找出第一个 k 和最后一个 k 的位置
 *
 * 运行时间：3ms
超过31.46% 用C++提交的代码
占用内存：552KB
超过19.77%用C++提交的代码
 */
int GetNumberOfK(vector<int> data ,int k) {
    int firstK = getFirst(data, k);
    int lastK = getLast(data, k);

    if (firstK != -1 && lastK != -1) {
        return lastK - firstK + 1;
    }

    return 0;
}