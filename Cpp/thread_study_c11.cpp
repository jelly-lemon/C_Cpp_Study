#include<iostream>
#include<thread>
#include <mutex>
#include <windows.h>
//#include <functional>
using namespace std;





class A {
public:
    static void* sayHello(void *args) {
        cout << "hello" << endl;
        return NULL;
    }
};

void t_main() {
    cout << "t_main" << endl;
    Sleep(3000);

    cout << "t_main finished" << endl;
}

int g_n = 1;
mutex m;

void t_1() {
    while (1) {
        lock_guard<mutex> guard(m);
        cout << "t_1:" << g_n << endl;
        g_n++;
        Sleep(1000);
    }
}

void t_2() {
    while (1) {
        lock_guard<mutex> guard(m);
        cout << "t_2:" << g_n << endl;
        g_n++;
        Sleep(1000);
    }
}



/**
 * 创建线程并运行
 *
 * 如果主线程不 join 子线程的话，会出现 terminate called without an active exception
 * 原因：主线程在任务线程还没有执行完成就退出了，销毁了一些资源，导致任务线程就异常了
 *
 * detach(): 从 thread 对象分离执行的线程，允许执行独立地持续。一旦线程退出，
 * 则释放所有分配的资源。调用 detach 后， *this 不再占有任何线程。
 * detach 之后，主线程退出，子线程会被强制消灭。
 */

void test_0() {
    thread t0(t_main);  // 创建线程，并直接运行
    //t0.join();  // 调用该函数会阻塞当前线程，直到由 *this 所标示的线程执行完毕 join 才返回。
    t0.detach();
}

/**
 * 互斥锁与线程同步
 */
void test_1() {
    thread thread1(t_1);
    thread thread2(t_2);
    thread1.join();
    thread2.join();
}


/**
 * 用静态函数创建线程
 */
void test_2() {
    thread t(A::sayHello, (void*)NULL);
}

int main() {




    return 0;
}