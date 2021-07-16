
#include <windows.h>

/**
 * 解析命令行参数
 *
 * lpCmdLine 包含了参数，不过是一个字符串（不包含程序名）
 */
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    int argc = 0;
    LPWSTR *argv = CommandLineToArgvW((LPCWSTR)GetCommandLine(), &argc);
/*	for (int i = 0; i < argc;++i)
	{
		MessageBox(0, argv[i], L"cmdLine", 0);
	}*/
    for (int i=0; i < argc; ++i)
    {
        LPWSTR cmd = argv[i];
        int len;
        len = WideCharToMultiByte(CP_UTF8, NULL, cmd, wcslen(cmd), NULL, 0, NULL, NULL);
        char *str_ascii = new char[len + 1];
        ZeroMemory(str_ascii, len + 1);
        WideCharToMultiByte(CP_UTF8, NULL, cmd, wcslen(cmd), str_ascii, len, NULL, NULL);
        str_ascii[len] = '\0';
        if (strcmp(str_ascii, "-u") == 0)
        {
            MessageBox(0, "-u", "cmdLine", 0);
        }
    }

    return 0;
}

