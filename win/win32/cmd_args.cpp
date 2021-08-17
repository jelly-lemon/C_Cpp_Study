
#include <windows.h>
#include <cstdio>

using namespace std;

/**
 * ���������в���
 *
 * lpCmdLine �����˲�����������һ���ַ�������������������
 *
 * WinMain: LPSTR
 * wWinMain:LPWSTR lpCmdLine
 */
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    int argc = 0;

    //
    // ��ȡ Unicode �����в���
    //
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    //
    // ����ת��
    //
    char **newArgv = (char**)malloc(argc*sizeof(char*));
    for (int i = 0; i < argc; ++i) {
        LPWSTR cmd = argv[i];
        //
        // Unicode ת utf-8
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
 * ���ͬʱ���� WinMain �� main�����ִ�� main
 */
//int main() {
//
//    return 0;
//}
