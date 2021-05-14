/*
 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
 如果不存在则输出0。

 {1,2,3,2,2,2,5,4,2} --> 2
 {2,1,3,4,5} --> 0 不存在超过数组长度一半的数字

 问：如何判断是否存在超过一半的数字呢？
 答：取到中间数字后，再计数

 思路 1：快排后，取中间的数字
 */
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


void printVector(vector<int> v) {
    for (int &n : v) {
        cout << n << " ";
    }
    cout << endl;
}

/*
 运行时间：3ms
超过30.10%用C++提交的代码
占用内存：376KB
超过89.58%用C++提交的代码
 */
int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() == 0)
        return 0;
    unordered_map<int, int> map1;
    int halfLen = numbers.size()/2;
    for (int &i : numbers) {
        if (map1.find(i) == map1.end()) {
            map1[i] = 1;
            if (map1[i] > halfLen)
                return i;
        } else {
            map1[i]++;
            if (map1[i] > halfLen)
                return i;
        }
    }
    return 0;
}


/**
 * 快速排序（递归结构）
 */
void quickSort(vector<int> &numbers, int start, int n) {
    if (numbers.size() == 1)
        return;
    if (n <= 1)
        return;

    int mid, i, j;
    mid = 0;
    i = 1;
    j = start + n - 1;
    while(i < j) {
        while (i < j) {
            if (numbers[j] < numbers[mid]) {
                break;
            } else {
                j--;
            }
        }
        while (i < j) {
            if (numbers[i] > numbers[mid]) {
                int t = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = t;
                break;
            } else {
                i++;
            }
        }
        if (i < j) {
            int t = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = t;
        }
    }
    int t = numbers[i];
    numbers[i] = numbers[mid];
    numbers[mid] = t;


    cout << "mid value: " << numbers[mid] << endl;
    printVector(numbers);

    // 递归快速排序
    quickSort(numbers, 0, mid);
    quickSort(numbers, mid+1, n-mid-1);
}

/**
 * 快速基排序，即把中轴元素放到正确位置上
 */
void quickBase_2(vector<int> &numbers, int start, int n) {
    if (n == 0)
        return;

    cout << "before:";
    for (int i = 0; i < start; i++) {
        cout << "  ";
    }
    vector<int> v1(numbers.begin()+start, numbers.begin()+start+n);
    printVector(v1);

    int low = start;
    int high = start + n - 1;
    int pivot = start; // 轴下标
    int t;
    // 【易糊涂点】循环判断条件到底是 high >= low 还是 high > low ？
    while (high > low) {
        // 【易糊涂点】循环判断条件 numbers[high] >= pivot 还是 numbers[high] > pivot ？
        while (numbers[high] >= numbers[pivot] && high > low) {
            high--;
        }
        if (high <= low) {
            break;
        } else {
            t = numbers[high];
            numbers[high] = numbers[pivot];
            numbers[pivot] = t;
            pivot = high;
        }
        while (numbers[low] <= numbers[pivot] && high > low) {
            low++;
        }
        if (high <= low) {
            break;
        } else {
            t = numbers[low];
            numbers[low] = numbers[pivot];
            numbers[pivot] = t;
            pivot = low;
        }
    }
    cout << " after:";
    for (int i = 0; i < start; i++) {
        cout << "  ";
    }
    vector<int> v2(numbers.begin()+start, numbers.begin()+start+n);
    printVector(v2);

    int leftN = pivot - start;
    int rightN = n - leftN - 1; // 【易错点】右边元素数量
    quickBase_2(numbers, start, leftN);
    quickBase_2(numbers, pivot+1, rightN);
}

void quickSort_2(vector<int> &numbers) {
    printVector(numbers);
    quickBase_2(numbers, 0, numbers.size());
    printVector(numbers);
}



/**
 * 判断排序数组是否存在一个数字超过数组长度一半
 */
int isMoreThanHalf(const vector<int> &numbers) {
    int halfSize = numbers.size() / 2;
    int mid = halfSize - 1; // 中间元素下标
    int count = 0;
    for (const int &n : numbers) {
        // 记录有多少元素值等于中间元素值
        if (n == numbers[mid])
            count++;
    }
    // 超过一半元素，也就是存在一个数字超过数组长度一半
    if (count >= halfSize) {
        return numbers[mid];
    } else {
        return 0;
    }
}



/**
 * 测试快排
 */
void test_0() {
    vector<int> v{1,2,3,2,2,2,5,4,2};
    printVector(v);
    quickSort(v, 0, v.size());
    printVector(v);

}

int MoreThanHalfNum_Solution_1(vector<int> numbers) {
//    quickSort(numbers);
    printVector(numbers);
    return isMoreThanHalf(numbers);
}

void test_1() {
    int a[] = {1,2,3,2,2,2,5,4,2};
    vector<int> v(a, a+9);
    printVector(v);
    cout << MoreThanHalfNum_Solution(v) << endl;
}

void test_2() {
    vector<int> v1 = {5,7,9,4,3,8,1,2,6,0};
    quickSort_2(v1);
}
int main() {
    test_2();
    return 0;
}