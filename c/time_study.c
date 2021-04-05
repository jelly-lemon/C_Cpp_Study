#include <time.h>
#include <stdio.h>
#include <windows.h>

/**
 * 打印当前时间，精确到秒
 */
void test_1() {
    time_t t;
    struct tm *lt;

    // 获取当前时间，精度只能到秒
    time(&t); // t = time(NULL) 也可以

    lt = localtime(&t);//转为时间结构。

    printf("%d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday,
           lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
}

/**
 * 计算时间差，精确到毫秒
 * 1s = 1000ms
 */
void test_2() {
    DWORD t_start, t_end;
    t_start = GetTickCount();//从操作系统启动所经过（elapsed）的毫秒数，它的返回值是DWORD。
    Sleep(1234);
    t_end = GetTickCount();
    printf("start:%ld\n", t_start);
    printf("end:%ld\n", t_end);
    printf("interval:%ld", t_end - t_start);
}


int main() {
    test_1();


    return 0;

}