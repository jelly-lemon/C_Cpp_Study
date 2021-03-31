/**
 * 线程差错：自增自减差错
 *
 * a 初值为 0
 * 多个线程对全局变量进行 n 次的自增操作，同样多个线程对全局变量进行 n 次自减操作，
 * 然后同时启动全部线程
 * 我们预测：最后 a 的值仍为 0
 *
 * 但结果不是！最终 a 的值处于不确定状态
 * 原因：出现增线程和减线程同时取值(减线程慢那么一丢丢)，然后分别进行增和减操作，
 * 输出的结果就好像：0 -> 1 -> -1，本来应该是 0 -> 1 -> 0
 */
#include <stdio.h>
#include <pthread.h>

int a = 0;

void* t_1(void *args) {
    int i;
    for (i = 0; i < 10000; i++) {
        a++;
    }
    return NULL;
}

void* t_2(void *args) {
    int i;
    for (i = 0; i < 10000; i++) {
        a--;
    }

    return NULL;
}



int main() {
    pthread_t t1[100];
    pthread_t t2[100];
    int i;
    int n_thread = 20;
    for (i = 0; i < n_thread; i++) {
        pthread_create(&t1[i], NULL, t_1, NULL);
        pthread_create(&t2[i], NULL, t_2, NULL);
    }
    for (i = 0; i < n_thread; i++) {
        pthread_join(t1[i], NULL);
        pthread_join(t2[i], NULL);
    }

    printf("%d\n", a);
    return 0;
}