/**
 * 如果直接传 类成员函数，会报错：
 * cannot convert 'Test::threadFunc' from type 'void* (Test::)(void*)' to type 'void* (*)(void*)'
 * 因为类成员函数必须由实例化对象来调用。
 */

#include<pthread.h>
#include <windows.h>
#include <iostream>
using namespace std;

class Test {
public:
    void start();
    static void* threadFunc(void *args);
};

void Test::start() {
    pthread_t t;
    pthread_create(&t, NULL, threadFunc, this);
}

void *Test::threadFunc(void *args) {
    Test *_this = (Test*) args;
    cout << "threadFunc" << endl;
    return NULL;
}

int main() {
    Test myTest;
    myTest.start();

    Sleep(3000);
    return 0;
}