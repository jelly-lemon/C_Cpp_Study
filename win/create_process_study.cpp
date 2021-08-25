#include<Windows.h>
#include<cstdio>
#include <tchar.h>

/**
 * 创建外部进程
 */
void test_0() {
    STARTUPINFO si; //STARTUPINFO用于指定新进程的主窗口特性的一个结构。
    PROCESS_INFORMATION pi;//在创建进程时相关的数据结构之一，该结构返回有关新进程及其主线程的信息。
    ZeroMemory(&si, sizeof(si)); /*分配内存*/
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // CreateProcess用来创建一个新的进程和它的主线程，这个新进程运行指定的可执行文件。
    // 阻塞等待，子进程结束，才会返回
    if (!CreateProcess(_T("C:\\Windows\\System32\\mspaint.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Creat Process Failed");
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);// hProcess：返回新进程的句柄,系统常量INFINITE Timeout时间无限
    printf("child Complete");
    CloseHandle(pi.hProcess);// hProcess：返回新进程的句柄
    CloseHandle(pi.hThread);// hThread:返回主线程的句柄
}

int main() {
    test_0();

    return 0;
}
