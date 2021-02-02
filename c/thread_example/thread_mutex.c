/**
 * 线程互斥锁的使用
 *
 * -- 学习目标 ----------
 * 互斥变量的创建；
 * 给互斥变量加锁、解锁；
 * 轮询等待锁；
 */


#include <stdio.h>
#include <pthread.h>
#include <windows.h>

pthread_mutex_t lock;   // 全局互斥量
int a = 100;
int b = 200;

void *threadA() {
    pthread_mutex_lock(&lock);  // 给互斥量加锁
    printf("thread A got the lock! a=%d, b=%d\n", a, b);
    a -= 50;
    Sleep(2000);
    b += 50;
    pthread_mutex_unlock(&lock);
    printf("thread A released the lock! a=%d, b=%d\n", a, b);
    a -= 50;    // 未加锁的情况下进行赋值操作，有可能其它线程正在读取或修改 a
}

void *threadB() {
    Sleep(1000);
    pthread_mutex_lock(&lock);
    printf("thread B got the lock! a=%d, b=%d\n", a, b);
    pthread_mutex_unlock(&lock);
    printf("thread B released the lock! a=%d, b=%d\n", a, b);
}

void *threadC() {
    while (pthread_mutex_trylock(&lock) == EBUSY) {
        printf("thread C is trying to get lock\n");
        Sleep(100);
    }
    printf("thread C got the lock! a=%d, b=%d\n", a, b);
    a = 1000;
    b = 2000;
    pthread_mutex_unlock(&lock);
    printf("thread C released the lock! a=%d, b=%d\n", a, b);
}

int main() {
    pthread_t tida, tidb, tidc;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&tida, NULL, threadA, NULL);
    pthread_create(&tidb, NULL, threadB, NULL);
    pthread_create(&tidc, NULL, threadC, NULL);

    pthread_join(tida, NULL);
    pthread_join(tidb, NULL);
    pthread_join(tidc, NULL);

    return 0;
}