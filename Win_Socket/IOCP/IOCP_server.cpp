#include <winsock2.h>
#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

//#pragma comment(lib, "ws2_32.lib")
//#pragma comment(lib, "kernel32.lib")

HANDLE g_hIOCP;

/**
 * IO 操作
 */
enum IO_OPERATION {
    IO_READ, IO_WRITE
};


/**
 * 存储 socket 及 IO 数据
 */
struct IO_DATA {
    OVERLAPPED Overlapped;
    WSABUF wsabuf;
    int nBytes;
    IO_OPERATION opCode;
    SOCKET client;
};

char buffer[1024];


DWORD WINAPI WorkerThread(LPVOID WorkThreadContext) {
    IO_DATA *lpIOContext = NULL;
    DWORD nBytes = 0;
    DWORD dwFlags = 0;
    int nRet = 0;

    DWORD dwIoSize = 0;
    void *lpCompletionKey = NULL;
    LPOVERLAPPED lpOverlapped = NULL;

    while (1) {
        // 从完成端口获取一个 IO 包，没有则会被挂起
        GetQueuedCompletionStatus(g_hIOCP, &dwIoSize, (PULONG_PTR) &lpCompletionKey,
                                  (LPOVERLAPPED *) &lpOverlapped, INFINITE);

        // 如果客户端已经关闭，跳出本次循环
        // 【疑问】为啥 lpOverlapped 可以转成 IO_DATA ?难道是因为Overlapped是结构体第一个成员？
        lpIOContext = (IO_DATA *) lpOverlapped;
        if (dwIoSize == 0) {
            cout << "Client disconnect" << endl;
            closesocket(lpIOContext->client);
            delete lpIOContext;
            continue;
        }

        // WSARecv 完成，也就是读操作完成
        if (lpIOContext->opCode == IO_READ) {
            cout << "recv: " << lpIOContext->wsabuf.buf << endl;

            ZeroMemory(&lpIOContext->Overlapped, sizeof(lpIOContext->Overlapped));
            char s[100] = "hello, I'm server.";
            lpIOContext->wsabuf.buf = s;
            lpIOContext->wsabuf.len = strlen(s) + 1;
            lpIOContext->opCode = IO_WRITE;
            lpIOContext->nBytes = strlen(s) + 1;
            dwFlags = 0;
            nBytes = strlen(s) + 1;

            // 响应客户端
            nRet = WSASend(
                    lpIOContext->client,
                    &lpIOContext->wsabuf, 1, &nBytes,
                    dwFlags,
                    &(lpIOContext->Overlapped), NULL);
            if (nRet == SOCKET_ERROR && (ERROR_IO_PENDING != WSAGetLastError())) {
                cout << "WASSend Failed::Reason Code::" << WSAGetLastError() << endl;
                closesocket(lpIOContext->client);
                delete lpIOContext;
                continue;
            }
            memset(buffer, '\0', sizeof(buffer));
        } else if (lpIOContext->opCode == IO_WRITE) {
            cout << "send: " << lpIOContext->wsabuf.buf << endl;

            // WSASend 完成，也就是写操作完成
            lpIOContext->opCode = IO_READ;
            nBytes = 1024;
            dwFlags = 0;
            lpIOContext->wsabuf.buf = buffer;
            lpIOContext->wsabuf.len = nBytes;
            lpIOContext->nBytes = nBytes;
            ZeroMemory(&lpIOContext->Overlapped, sizeof(lpIOContext->Overlapped));

            // 读取数据
            nRet = WSARecv(
                    lpIOContext->client,
                    &lpIOContext->wsabuf, 1, &nBytes,
                    &dwFlags,
                    &lpIOContext->Overlapped, NULL);
            if (nRet == SOCKET_ERROR && (ERROR_IO_PENDING != WSAGetLastError())) {
                cout << "WASRecv Failed::Reason Code1::" << WSAGetLastError() << endl;
                closesocket(lpIOContext->client);
                delete lpIOContext;
                continue;
            }
        }
    }
    return 0;
}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 创建监听 socket
    SOCKET m_socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(6000);
    server.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    bind(m_socket, (sockaddr *) &server, sizeof(server));
    listen(m_socket, 8);

    // 获取 CPU 逻辑核心数
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    int g_ThreadCount = sysInfo.dwNumberOfProcessors * 2;

    // 创建完成端口
    g_hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, g_ThreadCount);

    // 创建工作线程
    for (int i = 0; i < g_ThreadCount; ++i) {
        HANDLE hThread;
        DWORD dwThreadId;
        hThread = CreateThread(NULL, 0, WorkerThread, 0, 0, &dwThreadId);
        // 【注意】线程句柄（Handle）是内核对象，是系统资源，如果后面用不到了，就可以释放掉。不是结束线程的意思。
        // 线程句柄可以用改改变线程优先级等。
        CloseHandle(hThread);
    }

    while (1) {
        // 等待客户端连接
        SOCKET client = accept(m_socket, NULL, NULL);
        cout << "Client connected." << endl;

        // 将连接 socket 与完成端口绑定
        if (CreateIoCompletionPort((HANDLE) client, g_hIOCP, 0, 0) == NULL) {
            cout << "Binding Client Socket to IO Completion Port Failed::Reason Code::" << GetLastError() << endl;
            closesocket(client);
        } else {
            // 初始化 IO_DATA 结构体
            IO_DATA *data = new IO_DATA;
            memset(buffer, '\0', 1024);
            memset(&data->Overlapped, 0, sizeof(data->Overlapped));
            data->opCode = IO_READ;
            data->nBytes = 0;
            data->wsabuf.buf = buffer;
            data->wsabuf.len = sizeof(buffer);
            data->client = client;
            DWORD nBytes = 1024, dwFlags = 0;

            // WSARecv 非阻塞，在这个 Socket 上提交一个读取数据的请求，然后内核就会去读取数据
            int nRet = WSARecv(client, &data->wsabuf, 1, &nBytes,
                               &dwFlags,
                               &data->Overlapped, NULL);
            if (nRet == SOCKET_ERROR && (ERROR_IO_PENDING != WSAGetLastError())) {
                cout << "WASRecv Failed::Reason Code::" << WSAGetLastError() << endl;
                closesocket(client);
                delete data;
            }
        }
    }
    closesocket(m_socket);
    WSACleanup();
}