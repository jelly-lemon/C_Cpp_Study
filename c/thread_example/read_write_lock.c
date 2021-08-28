/**
 * 【多线程读写锁差错】
 * 多个线程在读，多个线程在写，会带来读线程读到脏数据的问题。
 *
 * 读线程正在读时，写线程不能写。
 * 读线程有可能读取到的是写线程写之前的数据，读线程刚把数据取出来，但真实数据已经被写线程改变了。
 * 这就导致读线程拿到的数据不是最新的数据。
 *
 * 写线程正在写时，读线程不能读。
 *
 * 当既加了写锁，又加了读锁，那到底 pthread_rwlock_unlock 是释放哪一个锁？
 * 笨蛋，不可能同时加写锁和读锁。
 */

#include <stdio.h>
#include <pthread.h>
#include <windows.h>

int value;
pthread_rwlock_t rwlock;    // 创建一个读写锁

/**
 * 模拟写操作的函数
 */
void *t_write(void *args) {
    int k = *(int*) args;
    while (value <= 500) {
        // 写加锁
        pthread_rwlock_wrlock(&rwlock);
        // 有可能进入循环时 value 还小于 500，但获得锁时 value 已经 >= 500
        if (value <= 500)
            printf("value=%d,thread_id=%d -------write\n", value += 50, k);
        // 解锁
        pthread_rwlock_unlock(&rwlock);
        Sleep(1000);
    }
    return NULL;
}

/**
 * 模拟读操作的函数
 */
void *t_read(void *args) {
    int k = *(int*) args;
    while (value <= 500) {
        // 读加锁
        pthread_rwlock_rdlock(&rwlock);
        // 有可能进入 while 时 value <= 500，但卡在了获得读锁这里，过了一段时间后获得了读锁，结果 value 已经 >= 500 了
        if (value <= 500)
            printf("value=%d,thread_id=%d -------read\n", value, k);
        pthread_rwlock_unlock(&rwlock);
        Sleep(1000);
    }
    return NULL;
}

/**
 * 开启多线程模拟读写操作
 */
void read_write_test() {
    int i;
    pthread_t pt[10];

    // 初始化读写锁
    pthread_rwlock_init(&rwlock, NULL);
    value = 0;
    for (i = 0; i < 5; i++) {
        int k = i;
        pthread_create(&pt[i], NULL, t_write, (void *) &k);
    }

    for (i = 5; i < 10; i++) {
        int k = i;
        pthread_create(&pt[i], NULL, t_read, (void *) &k);
    }

    // 主线程等待全部子线程完成
    for (i = 0; i < 10; i++) {
        // TODO 如果线程被阻塞了，join() 会立即返回吗？
        pthread_join(pt[i], NULL);
    }
    // 释放读写锁
    pthread_rwlock_destroy(&rwlock);
}

int main() {
    read_write_test();

    return 0;
}