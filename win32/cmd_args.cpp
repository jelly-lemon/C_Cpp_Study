
#include <windows.h>
#include <cstdio>

using namespace std;

/**
 * 解析命令行参数
 *
 * lpCmdLine 包含了参数，不过是一个字符串（不包含程序名）
 *
 * WinMain: LPSTR
 * wWinMain:LPWSTR lpCmdLine
 */
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    int argc = 0;

    //
    // 获取 Unicode 命令行参数
    //
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    //
    // 挨个转换
    //
    char **newArgv = (char**)malloc(argc*sizeof(char*));
    for (int i = 0; i < argc; ++i) {
        LPWSTR cmd = argv[i];
        //
        // Unicode 转 utf-8
        //
        int len = WideCharToMultiByte(CP_UTF8, NULL, cmd, wcslen(cmd), NULL, 0, NULL, NULL);
        char *strUTF8 = (char*)malloc((len+1)*sizeof(char));
        ZeroMemory(strUTF8, len + 1);
        WideCharToMultiByte(CP_UTF8, NULL, cmd, wcslen(cmd), strUTF8, len, NULL, NULL);
        newArgv[i] = strUTF8;
        printf("argv[%d]:%s\n", i, newArgv[i]);
    }

    return 0;
}


/**
 * 如果同时存在 WinMain 和 main，则会执行 main
 */
//int main() {
//
//    return 0;
//}
