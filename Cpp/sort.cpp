/*
 * 排序算法
 */
#include <gtest/gtest.h>




/*
 * 递归形式的快速排序
 * 三 while(i_front < i_back)
 */
void QuickSort(int* a, int len) {
    int t;
    int i_center;   // 中轴元素下标
    int i_front, i_back;

    if (len <= 1)
        return;

    i_center = 0;
    i_front = 0;
    i_back = len - 1;
    while (i_front < i_back) {
        // 从后往前找比中轴元素小的元素
        while (i_front < i_back) {
            if(a[i_center] > a[i_back]) {
                t = a[i_center];
                a[i_center] = a[i_back];
                a[i_back] = t;
                i_center = i_back;
                break;
            }
            i_back--;
        }

        // 从前往后找比中轴元素大的元素
        while (i_front < i_back) {
            if(a[i_center] < a[i_front]) {
                t = a[i_center];
                a[i_center] = a[i_front];
                a[i_front] = t;
                i_center = i_front;
                break;
            }
            i_front++;
        }
    }
    QuickSort(a, i_center+1);
    QuickSort(a + i_center + 1, len - (i_center+1));
}

/**
 * 冒泡排序
 */
void BubbleSort(int* a, int len) {
    int i, j, t;

    // 外层 for 循环表示进行多少次冒泡基排序
    for (i = 0; i < len-1; i++) {
        // 冒泡基排序
        // j 代表要进行比较的元素下标
        for (j = 0; j < len-i-1; j++) {
            if (a[j] > a[j+1]) {
               t = a[j];
               a[j] = a[j+1];
               a[j+1] = t;
            }
        }
    }
}

TEST(testcase0, test_BubbleSort) {
    int data_1[10] = {1,2,3,4,5,6,7,8,9,0};
    int data_2[10] = {1,0,3,4,5,6,7,8,9,2};
    int data_3[10] = {1,2,3,4,7,6,5,8,9,0};
    int data_4[10] = {0,9,8,7,6,5,4,3,2,1};
    int expect[10] = {0,1,2,3,4,5,6,7,8,9};

    BubbleSort(data_1, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_1, expect, 10 * sizeof(int)), 0);

    BubbleSort(data_2, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_2, expect, 10 * sizeof(int)), 0);

    BubbleSort(data_3, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_3, expect, 10 * sizeof(int)), 0);

    BubbleSort(data_4, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_4, expect, 10 * sizeof(int)), 0);
}

TEST(testcase0, test_QuickSort) {
    int data_1[10] = {1,2,3,4,5,6,7,8,9,0};
    int data_2[10] = {1,0,3,4,5,6,7,8,9,2};
    int data_3[10] = {1,2,3,4,7,6,5,8,9,0};
    int data_4[10] = {0,9,8,7,6,5,4,3,2,1};
    int expect[10] = {0,1,2,3,4,5,6,7,8,9};

    QuickSort(data_1, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_1, expect, 10 * sizeof(int)), 0);

    QuickSort(data_2, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_2, expect, 10 * sizeof(int)), 0);

    QuickSort(data_3, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_3, expect, 10 * sizeof(int)), 0);

    QuickSort(data_4, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_4, expect, 10 * sizeof(int)), 0);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}