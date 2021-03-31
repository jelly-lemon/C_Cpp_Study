/**
 * 求十进制正整数对应的二进制位数
 */
#include "gtest/gtest.h"
#include <iostream>
using namespace std;


/**
 * 时间复杂度怎么分析呢？输入始终是一个数字啊
 * 应该把输入看作是二进制
 * 二进制的长度为 n，那么最坏时间复杂度为 O(n)
 */
int get_binary_one_1(int n) {
    if (n == 0)
        return 0;
    if (n < 0)
        n = -n;
    int count = 0;
    while (n > 0) {
        if (n&1 == 1)
            count++;
        n = n >> 1;
    }
    return count;
}

TEST(TestCase_0, test_0) {
    int n1 = 1;
    int expect1 = 1;
    int n2 = 12;
    int expect2 = 2;
    int n3 = 123;
    int expect3 = 6;
    int n4 = 1234;
    int expect4 = 5;
    int n5 = -1234;
    int expect5 = 5;

    EXPECT_EQ(expect1, get_binary_one_1(n1));
    EXPECT_EQ(expect2, get_binary_one_1(n2));
    EXPECT_EQ(expect3, get_binary_one_1(n3));
    EXPECT_EQ(expect4, get_binary_one_1(n4));
    EXPECT_EQ(expect5, get_binary_one_1(n5));
}

int main(int argc, char **argv) {
    // 初始化测试用例环境
    testing::InitGoogleTest(&argc, argv);

    // 执行所有的测试用例
    return RUN_ALL_TESTS();
}
