/**
 * CPU 的利用率是如何计算的？
 *
 * 做实验：
 * 用的 6 核 6 线程的 CPU
 *
 * 实验前我的猜想：
 * 一个进程中包含 1 个死循环线程：CPU 利用率：%17
 * 一个进程中包含 2 个死循环线程：CPU 利用率：%34
 * 一个进程中包含 3 个死循环线程：CPU 利用率：%51
 * 一个进程中包含 4 个死循环线程：CPU 利用率：%68
 * 一个进程中包含 5 个死循环线程：CPU 利用率：%85
 * 一个进程中包含 6 个死循环线程：CPU 利用率：%100
 *
 * 实验数据：
 * 一个进程中包含 1 个死循环线程，CPU 利用率：23%
 * 一个进程中包含 2 个死循环线程，CPU 利用率：46%
 * 一个进程中包含 3 个死循环线程，CPU 利用率：69%
 * 一个进程中包含 4 个死循环线程，CPU 利用率：90%
 * 一个进程中包含 5 个死循环线程，CPU 利用率：97%
 * 一个进程中包含 6 个死循环线程，CPU 利用率：97%
 *
 * 我的理解：
 * 虽然 CPU 支持 6 线程，但是线程的切换也很耗时。
 * 所以，当开启 5 个线程时，CPU 就有点力不从心了，把一部分精力花在了线程切换上。
 */

#include <stdio.h>
#include <pthread.h>
#include <windows.h>

void diedCircle();


void* thread_1(void *args) {
    diedCircle();
}


void diedCircle() {
    int count = 0;
    while (TRUE) {
        count++;
    }
}

void test_1() {
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_t t5;

    pthread_create(&t1, NULL, thread_1, NULL);
    pthread_create(&t2, NULL, thread_1, NULL);
    pthread_create(&t3, NULL, thread_1, NULL);
    pthread_create(&t4, NULL, thread_1, NULL);
    pthread_create(&t5, NULL, thread_1, NULL);

    diedCircle();
}


/**
 * 获取CPU 核心数
 */
int getLogicCores() {
    SYSTEM_INFO info;
    GetSystemInfo(&info);
    printf("logic_cores=%d\n", info.dwNumberOfProcessors);
    return info.dwNumberOfProcessors;
}

int main() {
    getLogicCores();

    return 0;
}