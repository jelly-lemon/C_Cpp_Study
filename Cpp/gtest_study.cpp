#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int Add(int a, int b) {
    return a + b;
}

// ====== 一组测试用例 ======
// 测试用例名，测试名
TEST(testCase, test0) {
    // 期望相等：期望值，返回值
    EXPECT_EQ(14, Add(4, 10));
}

TEST(testCase, test1) {
    // ASSERT_EQ 与 EXPECT_EQ 区别？
    // ASSERT_* 的断言：当检查点失败时，退出当前函数；
    // EXPECT_* 的断言：当检查点失败时，继续往下执行，最后在结果中输出期望值和实际值。
    ASSERT_EQ(6, Add(5, 7));
}

TEST(testCase, test2) {
    // 返回 cout，后面就可以直接 cout 了
    EXPECT_EQ(28, Add(8, 10)) << "bugs";
}

// ====== 一组测试用例 ======
TEST(testCase_1, test_0) {
    // 判断两个数组是否相等
    int data[2] = {1, 2};
    int expect[2] = {1, 2};
    EXPECT_EQ(memcmp(data, expect, 2 * sizeof(int)), 0);
}

// ====== 自定义测试用例 ======
class TestMap : public testing::Test {
public:
    map<int, int> test_map;

    // 日志
    static void SetUpTestCase() {
        cout << "My SetUpTestCase" << endl;
    }

    static void TearDownTestCase() {
        cout << "My TearDownTestCase" << endl;
    }

    virtual void SetUp() {
        cout << "My SetUp" << endl;
        test_map.insert(make_pair(1, 0));
        test_map.insert(make_pair(2, 1));
        test_map.insert(make_pair(3, 2));
        test_map.insert(make_pair(4, 3));
        test_map.insert(make_pair(5, 4));
    }

    virtual void TearDown() {
        cout << "My TearDown" << endl;
        test_map.clear();
    }
};

// TEST_F 对单独创建一个 TestMap 对象，
// 会执行 setUp 和 tearDown
// 还可以在函数里访问属性
// 各个 TEST_F 相互独立
TEST_F(TestMap, Find) {
    map<int, int>::iterator it = test_map.find(1);
    // NE 表示 not equal
    ASSERT_NE(it, test_map.end());
}

TEST_F(TestMap, Size) {
    ASSERT_EQ(test_map.size(), 5);
}


int main(int argc, char **argv) {
    cout << "Hello, World!" << endl;

    // 初始化测试用例环境
    testing::InitGoogleTest(&argc, argv);

    // 执行所有的测试用例
    return RUN_ALL_TESTS();
}
