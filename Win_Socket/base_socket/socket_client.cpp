/**
 * 客户端简单的 Socket 使用
 */

// 以下库来自的编译器
#include <stdio.h>
#include <winsock2.h>
#include <inaddr.h>

int main() {
    WORD wVersionRequested; // WORD 就是 unsigned short，无符号短整型
    WSADATA wsaData;    // 一个结构体。这个结构被用来存储被WSAStartup函数调用后返回的Windows Sockets数据。
    int err;

    wVersionRequested = MAKEWORD(1, 1); // 将两个 byte 型合并成一个 word 型,一个在高8位(b),一个在低8位(a)
    // 整数 1 是 byte 类型吗？

    err = WSAStartup(wVersionRequested, &wsaData);  // 即WSA(Windows Sockets Asynchronous，Windows异步套接字)的启动命令
    if (err != 0) {
        return -1;
    }

    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
        WSACleanup();   // 功能是终止Winsock 2 DLL (Ws2_32.dll) 的使用
        exit(-1);
    }

    SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);    // 创建 socket 套接字

    SOCKADDR_IN addrSrv;    // 保存服务端的信息
    addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  // inet_addr 将一个IP字符串转化为一个网络字节序的整数值
    addrSrv.sin_family = AF_INET;   // AF_INET 表示 IPv4 地址
    addrSrv.sin_port = htons(6000); // 端口号  htons是将整型变量从主机字节顺序转变成网络字节顺序， 就是整数在地址空间存储方式变为高位字节存放在内存的低地址处。
    connect(sockClient, (SOCKADDR *) &addrSrv, sizeof(SOCKADDR)); // 和服务端进行连接（阻塞等待，直到连上）
    send(sockClient, "hello", strlen("hello") + 1, 0);    // 发送消息
    char recvBuf[50];
    recv(sockClient, recvBuf, 50, 0);   // 接收来自服务端的消息（阻塞等待，直到收到消息）
    printf("Server reply:\n");
    printf("%s\n", recvBuf);

    closesocket(sockClient);    // 关闭 socket 连接
    WSACleanup();   // 功能是终止Winsock 2 DLL (Ws2_32.dll) 的使用

    return 0;
}

