/**
 * 写一个程序，控制 CPU 的利用率
 *
 * cpu的占有率是由进程的忙和空闲来决定的，即：rate=(busy_time)/(busy_time+idle_time)
 *
 * 前提条件：把情况理想化一下，没有任何其它程序在运行，CPU 是 6 核 6 线程。
 */

#include <pthread.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>


/**
 * 自定义 sin 函数，幅值 [0, 1]，中间轴为 y = 0.5
 *
 * @param x 角度，0~360
 * @return sin 函数值，[0, 1]
 */
double my_sin(int x) {
    double PI = 3.14159265;
    double val = PI / 180;

    return sin(x * val) / 2 + 0.5;
}

/**
 * 运行指定时间，到了时间就退出
 *
 * @param run_time 目标运行时间，毫秒
 */
void run(unsigned long run_time) {
    DWORD t_start, t_end;
    t_start = GetTickCount();

    while (1) {
        t_end = GetTickCount();
        if (t_end - t_start >= run_time) {
            break;
        }
    }
}

/**
 * 无限循环运行和 sleep
 */
void *thread_run_and_sleep_forever(void *args) {
    int refresh_time = 200; // 取 100 的整倍数，并且是 1000 的因数，可取的有：100，200，500，1000

    float ratio = *(float *) args;
    int run_ms = refresh_time * ratio;
    int sleep_ms = refresh_time - run_ms;
    int i;
    int times = 1000 / refresh_time;

    while (1) {
        for(i = 0; i < times; i++) {
            run(run_ms);
            Sleep(sleep_ms);
        }
    }
}

/**
 * 单次运行和 sleep
 */
void *thread_run_and_sleep_once(void *args) {
    int refresh_time = 500; // 取 100 的整倍数，并且是 1000 的因数，可取的有：100，200，500，1000

    float ratio = *(float *) args;
    int run_ms = refresh_time * ratio;
    int sleep_ms = refresh_time - run_ms;
    int i;
    int times = 1000 / refresh_time;

    for(i = 0; i < times; i++) {
        run(run_ms);
        Sleep(sleep_ms);
    }
}


/**
 * 获取 CPU 逻辑核心数
 */
int getMaxThreadNumber() {
    SYSTEM_INFO info;
    GetSystemInfo(&info);
    printf("NumberOfProcessors=%d\n", info.dwNumberOfProcessors);
    return info.dwNumberOfProcessors;
}


/**
 * 指定 CPU 占用率进行运行
 *
 * @param ratio 占用率，比如 0.1
 */
void run_by_ratio(float ratio) {
    pthread_t *p;
    int n_thread = getMaxThreadNumber() - 1;
    int i;

    p = (pthread_t *) malloc(sizeof(pthread_t) * n_thread);

    for (i = 0; i < n_thread; i++) {
        pthread_create(&p[i], NULL, thread_run_and_sleep_forever, (void *) &ratio);
    }

    thread_run_and_sleep_forever((void *) &ratio);
}

/**
 * sin 函数占用率
 */
void sin_ratio() {
    pthread_t *p;
    int n_thread = getMaxThreadNumber() - 1;
    int i;
    float ratio;

    int sin_epoch = 12; // 设置 sin 函数周期，单位 s
    int count = 0;

    p = (pthread_t *) malloc(sizeof(pthread_t) * n_thread);

    while (1) {
        // 计算本次 1s 时间内 CPU 应该忙率时间占比
        ratio = my_sin(((double) count / sin_epoch) * 360);
        printf("ratio=%f\n", ratio);

        // 根据 CPU 逻辑核心数创建线程并执行耗时函数
        for (i = 0; i < n_thread; i++) {
            pthread_create(&p[i], NULL, thread_run_and_sleep_once, (void *) &ratio);
        }

        // 主线程同样也执行耗时函数
        thread_run_and_sleep_once((void *) &ratio);

        // 循环计数
        count++;
        if (count >= sin_epoch) {
            count = 0;
        }
    }
}


int main() {
    // 关闭 stdout 缓冲
    setbuf(stdout, NULL);

    sin_ratio();

    return 0;
}
