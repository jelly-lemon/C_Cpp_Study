/**
 * 左值引用：引用一个左值
 * 右值引用：引用一个右值
 */

#include <iostream>
#include <functional>

using namespace std;


class Student {
private:
    int mAge;
public:

    void setAge(int age) {
        mAge = age;
    }

    int getAge() {
        return mAge;
    }
};

int getAge() {
    int age = 10;
    return age;
}

void fun_1(int &n) {
    cout << "fun_1 before, n:" << n << endl;
    n++;
    cout << "fun_1 after, n:" << n << endl;
}

void fun_2(int n) {
    cout << "fun_2 before, n:" << n << endl;
    n++;
    cout << "fun_2 after, n:" << n << endl;
}

template <class T>
void fun_3(T n) {
    cout << "fun_3 before, n:" << n << endl;
    n++;
    cout << "fun_3 after, n:" << n << endl;
}

/**
 * 左值引用
 */
void test_0( ) {
    int a = 10;
    int &a1 = a;    // a1 为左值引用，引用了变量 a
    cout << "a:" << a << endl;
    cout << "a1:" << a1 << endl;
    const int &a2 = a;  // 常左值引用，a2 也为左值引用，不过限制了引用的使用，即不允许修改
}

/**
 * 右值引用
 */
void test_1() {
    // a1 为右值引用，即引用一个常量
    int &&a1 = 10;

    // 可以修改引用的对象，只要是一个常量就行
    for (int i = 0; i < 10; i++) {
        a1 = i; // 【疑问】奇怪，i 不是变量吗？
        cout << a1 << " ";
    }
    cout << a1 << " ";
    cout << endl;

    // 【特殊】常左值引用也可以对右值进行引用
    const int &a2 = 10;

    // 常右值引用
    const int &&a3 = 10;

    // 不合法的右值引用
    // Rvalue reference to type 'const int' cannot bind to lvalue of type 'const int'
    // 实际上是：
    // const int temp = 10;
    // const int &a4 = temp;
    // const int &&a4 = a3;
}


/**
 * 对引用进行引用？还是引用的最开始的元素
 */
void test_2() {
    int n = 5;
    fun_1(n);

    int &n2 = n;
    fun_1(n2);

    int &n3 = n2;
    fun_1(n3);
}

/**
 * ref 函数使用
 * ref()方法的返回值是reference_wrapper类型
 * 作用：使用std::ref可以在模板传参的时候传入引用
 *
 * 对普通函数，普通形参（即值传递），调用函数时传 func(ref(n)) 不生效
 */
void test_3() {
    int n = 5;
    fun_2(ref(n)); // 形参是值传递，这里传引用也不行
    cout << "n: " << n << endl;

    fun_3(ref(n)); // 形参是模板参数，传引用有效
    cout << "n: " << n << endl;
}

/**
 * move() 函数使用
 * move(): 将左值引用转换为右值引用
 */
void test_4() {
    int a1 = 10;
    int &&a2 = move(a1);
    a2 =15;

    // 非法：右值引用一个变量
    //int &&a3 = a1;
}




void test_5() {

}




int main() {
    test_5();

    return 0;
}