/**
 * 线程的创建
 *
 * -- 学习目标 ----------
 * 使用 pthread_create() 创建线程；
 * 使用 getpid() 和 pthread_self() 获取进程 id 和线程 id；
 * 使用 pthread_join() 等待线程完成；
 *
 * 线程运行的函数必须是非成员函数，因为成员函数第一个参数是 this 指针。
 * 所以，要么是 static 方法，要么就是一个普通函数
 */

#include <stdio.h>
#include <pthread.h>
#include <windows.h>


void* thread1(void *args) {
    pid_t pid;
    pthread_t tid;
    int i;

    pid = getpid();
    tid = pthread_self();
    printf("thread1 pid:%lld tid:%lld\n", pid, tid);

    for (i = 0; i < 10; i++) {
        printf("thread1:%d\n", i);
        Sleep(200); // 挂起 0.2s
    }
    return NULL;
}

void* thread2(void *args) {
    pid_t pid;
    pthread_t tid;
    int i;

    pid = getpid();
    tid = pthread_self();

    printf("thread2 pid:%lld tid:%lld\n", pid, tid);

    for (i = 0; i < 10; i++) {
        printf("thread2:%d\n", i);
    }
    return NULL;
}

void startThread() {
    pthread_t t1;
    pthread_t t2;
    pid_t pid;
    pthread_t tid;

    pid = getpid(); // 获取进程 id
    tid = pthread_self();   // 获取主线程 id

    printf("start t1\n");
    // TODO 第二个参数？
    pthread_create(&t1, NULL, thread1, NULL);   // 启动 t1 线程
    printf("start t2\n");
    pthread_create(&t2, NULL, thread2, NULL);   // 启动 t2 线程

    printf("main pid:%lld tid:%lld\n", pid, tid);
    pthread_join(t1, NULL); // 等待 t1 线程完成，阻塞等待
    printf("t1 end\n");
    pthread_join(t2, NULL);
    printf("t2 end\n");
}

int main() {
    startThread();

    return 0;
}