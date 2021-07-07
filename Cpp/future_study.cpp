
#include <iostream>
#include <future>
#include <synchapi.h>
#include <processthreadsapi.h>

using namespace std;

string sayHello() {
    cout << "pid: " << GetCurrentThreadId() << ", sayHello" << endl;
    Sleep(1000);
    return "hello";
}

/**
 * 获取异步执行函数的结果
 */
void test_0() {
    future<string> rt = async(sayHello);
    cout << "pid: " << GetCurrentThreadId() << ", test_0" << endl;
    string s = rt.get();
    cout << s << endl;
}


int main() {
    test_0();
    return 0;
}