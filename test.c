#include "cppunit/TestCase.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TextOutputter.h"
#include "Calculator.h"

// 自定义的测试用例需要继承 CppUnit::TestCase
class CalculatorTest : public CppUnit::TestCase
        {
                public:
                // 重写 runTest() 方法
                virtual void runTest() override
        {
            Calculator calculator;
            // 使用 CPPUNIT_ASSERT 进行断言
            CPPUNIT_ASSERT(3 == calculator.add(1, 2));
            CPPUNIT_ASSERT(1 == calculator.sub(2, 1));
        }
        };

int main() {
    /* 创建 TestCase */
    // 不需要调用 delete 销毁 TestCase 对象，该对象由 CppUnit 框架自动销毁
    CalculatorTest *testCase = new CalculatorTest;
    /* 创建 TestRunner */
    CppUnit::TestRunner runner;
    /* 注册 TestCase 到 TestRunner */
    runner.addTest(testCase);
    /* 创建 TestResult */
    CppUnit::TestResult result;
    /* 创建 TestListener */
    // TestResultCollector 用来接收测试用例执行结果
    CppUnit::TestResultCollector resultCollector;
    /* 注册 TestListener 到 TestResult */
    result.addListener(&resultCollector);
    /* 执行测试用例 */
    runner.run(result);
    /* 处理结果 */
    // TextOutputter 用来以文本的形式打印执行结果
    // 第二个参数为输出设备，类型为 std::ostream，这里传入std::cout，将结果打印到标准输出
    CppUnit::TextOutputter outputter(&resultCollector, std::cout);
    outputter.write();

    return 0;
}