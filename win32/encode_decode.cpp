#include <windows.h>
#include <iostream>

using namespace std;

/**
 * UTF-8 转 ANSI
 */
wchar_t* Utf8ToAnsi(const char* szU8)
{
    //预转换，得到所需空间的大小;
    int wcsLen = MultiByteToWideChar(CP_UTF8, 0, szU8, strlen(szU8), NULL, 0);

    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];

    //转换
    MultiByteToWideChar(CP_UTF8, 0, szU8, strlen(szU8), wszString, wcsLen);

    //最后加上'\0'
    wszString[wcsLen] = '\0';

    cout << wszString << endl;

    return wszString;
}

wchar_t* Utf8ToUnicode(const char *pChar) {
    if (!pChar) return NULL;
    wchar_t *pszBuf = NULL;
    // ACP == ANSI code page
    int needWChar = MultiByteToWideChar(CP_UTF8, 0, pChar, -1, NULL, 0);
    if (needWChar > 0) {
        pszBuf = new wchar_t[needWChar + 1];
        ZeroMemory(pszBuf, (needWChar + 1) * sizeof(wchar_t));
        MultiByteToWideChar(CP_UTF8, 0, pChar, -1, pszBuf, needWChar);
    }
    cout << pszBuf << endl;

    return pszBuf;
}



/**
 * unicode 转 UTF-8
 */
char* UnicodeToUtf8(const wchar_t* unicode) {
    int len;
    len = WideCharToMultiByte(CP_UTF8, 0, unicode, -1, NULL, 0, NULL, NULL);
    char *szUtf8 = (char*)malloc(len + 1);
    memset(szUtf8, 0, len + 1);
    WideCharToMultiByte(CP_UTF8, 0, unicode, -1, szUtf8, len, NULL, NULL);
    cout << szUtf8 << endl;
    return szUtf8;
}


/**
 * unicode 转 ANSI
 */
char *UnicodeToAnsi(wchar_t *pWideChar) {
    if (!pWideChar) return NULL;
    char *pszBuf = NULL;
    int needBytes = WideCharToMultiByte(CP_ACP, 0, pWideChar, -1, NULL, 0, NULL, NULL);
    if (needBytes > 0) {
        pszBuf = new char[needBytes + 1];
        ZeroMemory(pszBuf, (needBytes + 1) * sizeof(char));
        WideCharToMultiByte(CP_ACP, 0, pWideChar, -1, pszBuf, needBytes, NULL, NULL);
        cout << pszBuf << endl;
    }
    return pszBuf;
}


/**
 * ANSI 转 unicode
 */
wchar_t *AnsiToUnicode(char *pChar) {
    if (!pChar) return NULL;
    wchar_t *pszBuf = NULL;
    // ACP == ANSI code page
    int needWChar = MultiByteToWideChar(CP_ACP, 0, pChar, -1, NULL, 0);
    if (needWChar > 0) {
        pszBuf = new wchar_t[needWChar + 1];
        ZeroMemory(pszBuf, (needWChar + 1) * sizeof(wchar_t));
        MultiByteToWideChar(CP_ACP, 0, pChar, -1, pszBuf, needWChar);
    }
    cout << pszBuf << endl;

    return pszBuf;
}




/**
 * ANSI == 窄字节
 * UNICODE == 宽字节
 */
void test_0() {
    //
    // unicode 转 utf-8
    //
    wchar_t msgUnicode[100] = L"n你好";  // 加 L 表示 unicode 字符串
    cout << "sizeof(msgUnicode):" << sizeof(msgUnicode) << endl;    // 数组长度，字节数
    cout << "wcslen(msgUnicode):" << wcslen(msgUnicode) << endl;    // 字符个数（不是字节数）
    cout << "msgUnicode:" << msgUnicode << endl;
    char *pMsgUtf8 = UnicodeToUtf8(msgUnicode);

    //
    // ANSI(utf-8) 转 unicode
    //
    char msg2[100] = "n你好"; // 不加 L，那么编码方式跟随文件，相当于字节串
    cout << "sizeof(msg2):" << sizeof(msg2) << endl;
    cout << "strlen(msg2):" << strlen(msg2) << endl; // 字符数（utf-8 一个汉字占 3 字节？）
    cout << "msg2:" << msg2 << endl;
    wchar_t *pMsg2Unicode = Utf8ToUnicode(msg2);
    UnicodeToUtf8(pMsg2Unicode);
}


int main() {
    test_0();

    return 0;
}