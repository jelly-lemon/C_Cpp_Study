/**
 * 主线程有一个 scanf()，子线程不断在控制台输出
 * 我想测试一下子线程在控制台输出的同时还能不能在主线程中输入
 * 经过测试：结论是可以的（不过手速要快，输入完毕按下回车之前要保证没有其它输出，否则不算有效输入）
 */

#include <stdio.h>
#include <pthread.h>
#include <windows.h>


void* thread1() {
    pid_t pid;
    pthread_t tid;
    int i;

    pid = getpid();
    tid = pthread_self();
    printf("thread1 pid:%lld tid:%lld\n", pid, tid);

    for (i = 0; i < 100; i++) {
        printf("thread1:%d\n", i);
        Sleep(200); // 挂起 0.2s
    }
    return NULL;
}


int main() {
    pthread_t t1;
    pid_t pid;
    pthread_t tid;
    char data[100];

    pid = getpid(); // 获取进程程 id
    tid = pthread_self();   // 获取主线程 id

    printf("start t1\n");
    pthread_create(&t1, NULL, thread1, NULL);   // 启动 t1 线程

    printf("main pid:%lld tid:%lld\n", pid, tid);

    printf("Input:");
    scanf("%s", data);
    printf(">>> %s\n", data);

    pthread_join(t1, NULL); // 等待 t1 线程完成，阻塞等待
    printf("t1 end\n");

    return 0;
}