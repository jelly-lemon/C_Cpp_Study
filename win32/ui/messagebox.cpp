/**
 * 弹出一个消息框
 */
#include <windows.h>

/**
 * win32 入口函数
 *
 * @param hInstance
 * @param hPrevInstance
 * @param lpCmdLine
 * @param nCmdShow
 * @return
 */
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MessageBox(NULL, "hello,world", "TIPS", 0);

    return 0;
}

/**
 * 如果有 main 函数，则执行 main，不会执行 WinMain
 * 也可以在 main 中调用 WinMain
 *
 * 【重点】执行时调用 main 还是 WinMain，主要看子系统是什么
 * 子系统是控制台就调用：main，是窗口就调用 WinMain。
 */
int main() {
    WinMain(NULL, NULL, NULL, SW_SHOW);

    MessageBox(NULL, "hello,world", "TIPS", 0);
    return 0;
}