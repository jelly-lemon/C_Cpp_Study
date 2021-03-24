#include <iostream>
#include <gtest/gtest.h>

int Add(int a, int b) {
    return a+b;
}

// 测试用例名，测试名
TEST(testCase, test0){
    // 期望相等：期望值，返回值
    EXPECT_EQ(14, Add(4, 10));
}

TEST(testCase, test1){
    ASSERT_EQ(6, Add(5, 7));
}

TEST(testCase, test2){
    // 返回 cout，后面就可以直接 cout 了
    EXPECT_EQ(28, Add(8, 10)) << "bugs";
}

int main(int argc, char ** argv) {
    std::cout << "Hello, World!" << std::endl;

    // 初始化测试用例环境
    testing::InitGoogleTest(&argc, argv);

    // 执行所有的测试用例
    return RUN_ALL_TESTS();
}
