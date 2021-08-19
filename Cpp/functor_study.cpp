/**
 * 仿函数 == 重载 "()" 运算符，所有对象可以使用 () 这个运算符

 个人理解：仿函数就是没有名字的成员方法

 我封装了一个算法，里面要调用一个比较函数，这个函数只能有一个参数，
 调用方式： func(n)，只要你给的东西能这样调就行。

 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Student {
private:
    string name;

public:
    /**
     * 仿函数必须重载 "()" 运算符，就跟写一个普通函数一样
     */
    void operator() (const string &s1, const string &s2) const {
        cout << s1 << endl;
        cout << s2 << endl;
    }
};

/**
 * 自定义比较函数
 */
bool LengthIsLessThanFive(const string& str) {
      return str.length()<5;
}

/**
 * 加入一个参数，自定义比较阈值
 */
bool LengthIsLessThan(const string& str, int len) {
   return str.length()<len;
}

class Compare {
private:
    int len;
public:
    Compare(int len): len(len) {

    }

    /**
     * 实现仿函数
     */
    bool operator()(const string &s) const{
        if (s.length() < len) {
            return true;
        }

        return false;
    }
};

/**
 * 假设有一个 vector<string>，你的任务是统计长度小于 5 的 string 的个数，
 * 如果使用 count_if 函数的话，你的代码可能长成这样

 为了自定义比较阈值：我们有以下方法：
 - 比较函数两个参数：但count_if 只允许有一个参数
 - 全局变量：但众所周知，少用全局变量
 */
void test_0() {
    vector<string> vec;
    vec.push_back("hi");

    // 使用自定义比较函数
    int r1 = count_if(vec.begin(), vec.end(), LengthIsLessThanFive);
    cout << "r1=" << r1 << endl;

    // 使用自定义比较函数，但函数要穿两个参数，count_if 的实现决定了不能传两个参
    //int r2 = count_if(vec.begin(), vec.end(), LengthIsLessThan);

    // 但也不是不可以，可以使用 lambda 函数，相当于把哈数包装了一下
    int r3 = count_if(vec.begin(), vec.end(), [](const string& str){return LengthIsLessThan(str, 6);});
    cout << "r3=" << r3 << endl;

    // 使用仿函数
    Compare compare(10);
    int r4 = count_if(vec.begin(), vec.end(), compare);
    cout << "r4=" << r4 << endl;
}


/**
 * 使用仿函数

 这样单独使用没啥意义
 */
void test_1() {
    Student s1;
    s1("hello", "world");
}


int main() {
    test_0();

    return 0;
}