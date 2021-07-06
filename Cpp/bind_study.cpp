
#include <iostream>
#include <functional>
#include <list>
#include <algorithm>

using namespace std;

string func_1(string msg) {
    cout << "func_1: " <<  msg << endl;

    return msg;
}

void func_2(int n) {
    cout << "func_2: " << n << endl;
}



/**
 * bind 使用
 * 将带参函数包装成无参函数
 */
void test_1() {
    auto newFunc = bind(func_1, "hello");

    string s = newFunc();
    cout << s << endl;
}

/**
 * 1st指:传进来的参数应该放第1个
 */
void test_2() {
    int iarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> aList(iarray, iarray + 10);

    int k = 0;

    //
    // bind1st(greater<int>(), 8) 将 greater<int>() 和一个参数值 8 捆绑为一个函数对象。
    // 由于使用了 bind1st()，所以该函数相当于计算下述表达式: 8 > q
    // q 是容器中的对象
    // 如果将bind1st(greater<int>(), 8)改成 bind2nd(greater<int>(), 8)
    // 则表示：q > 8 , 此时结果就是2了。
    //
    k = count_if(aList.begin(), aList.end(), bind1st(greater<int>(), 8));
    cout << "Number elements < 8 == " << k << endl;
}


/**
 * 2nd指:传进来的参数放第2个
 */
void test_3() {

}

/**
 * 任务队列
 */
void test_4() {
    auto f1 = bind(func_1, "hello");
    auto f2 = bind(func_2, 6);

    list<function<void()>> myList;
    myList.push_back(f1);
    myList.push_back(f2);

    //
    // 有返回值可以写 auto r = f();
    // 但是有些方法又没有方法值，所以就不能通用。
    //
    for (auto &f : myList) {
        f();
    }
}

int main() {
    test_4();

    return 0;
}