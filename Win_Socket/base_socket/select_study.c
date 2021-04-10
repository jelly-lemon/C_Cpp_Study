/**
 * epoll 仅仅 Linux 系统才有，windows 有 IOCP
 *
 * Linux 系统上的 poll 函数，在 Windows 上对应着 WSAPoll 函数，你可能在一些开源的 pc 端软件中看到该函数的用法。这个函数是在 Windows Vista 和  Windows Server 2008  及以后版本引入的，也就是说在 Windows XP 和 Windows Server 2003 不可用。
 *
 */
#include <windows.h>


/**
 * select read
 */
void test_0() {
    // nfds 参数只在兼容 Berkeley socket 时才使用，平时置为 0
    // 正常情况，返回三个集合中满足期望条件的 socket 总数
    // 超时，返回 0；

    select(0, )
}

int main() {

    return 0;
}