/*
 * 排序算法
 */
#include <gtest/gtest.h>

void BubbleSort(int* a, int len) {
    int i, j, t;

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

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}