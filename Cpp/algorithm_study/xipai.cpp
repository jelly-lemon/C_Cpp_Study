/**
* 洗牌算法
 *
 * 如何产生一个长度为 100 的数组，里面填满数字 1-100 不重复，而且数组内数字排序必须纯随机。
*/
#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;
#define N 100

/**
 * 通过随机数的方式产生随机数组
 * 时间复杂度：O(n^2)
 * 空间复杂度：用了一个集合，O(n)
 */
void test_0() {
    //
    // time 函数返回从 1970 年 1 月 1 日午夜开始到现在逝去的秒数
    // 用于保证每次种子都不一样
    //
    srand(time(0));
    unordered_set<int> myset;
    int arr[N] = {0};
    for (int i = 0; i < N; i++) {
        //
        // 随机生成一个  [1,100] 的数
        //  rand() 返回非负整数，即 >= 0
        // 在 rand 被调用之前，srand 函数要先被调用，并且 srand 在整个程序中仅被调用一次，用于初始化种子
        //
        int n = rand() % 100 + 1;
        while (myset.find(n) != myset.end()) {
            n++;
            if (n > 100) {
                n = 1;
            }
        }
        myset.insert(n);
        arr[i] = n;
        cout << n << " ";
    }
}


/**
 * Fisher–Yates随机置乱算法也被称做高纳德置乱算法
 */
void test_1() {

}


int main() {
    test_0();


    return 0;
}