/**
 * 客户端简单的 Socket 使用
 */

// 以下库来自的编译器
#include <stdio.h>
#include <winsock2.h>

void close(SOCKET scok) {
    // 关闭 socket 连接
    closesocket(scok);
    // 清理环境
    WSACleanup();   // 功能是终止Winsock 2 DLL (Ws2_32.dll) 的使用
}

void test_1() {
    WORD wVersionRequested; // WORD 就是 unsigned short，无符号短整型
    WSADATA wsaData;    // 一个结构体。这个结构被用来存储被 WSAStartup 函数调用后返回的 Windows Sockets 数据。
    int err;
    wVersionRequested = MAKEWORD(1, 1); // 将两个 byte 型合并成一个 word 型,一个在高8位(b),一个在低8位(a)。整数 1 是 byte 类型吗？
    char recvBuf[50];
    int iResult;

    // 初始化套接字环境
    err = WSAStartup(wVersionRequested, &wsaData);  // 即WSA(Windows Sockets Asynchronous，Windows异步套接字)的启动命令
    if (err != 0) {
        return;
    }
    // 检查是否初始化成功
    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
        WSACleanup();   // 功能是终止 Winsock 2 DLL (Ws2_32.dll) 的使用
        exit(-1);
    }
    // 创建 socket 套接字
    SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
    // 配置待请求服务端参数
    SOCKADDR_IN addrSrv;    // 保存服务端的信息
    addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  // inet_addr 将一个IP字符串转化为一个网络字节序的整数值
    addrSrv.sin_family = AF_INET;   // AF_INET 表示 IPv4 地址
    addrSrv.sin_port = htons(6000); // 端口号  htons是将整型变量从主机字节顺序转变成网络字节顺序， 就是整数在地址空间存储方式变为高位字节存放在内存的低地址处。

    // 和服务端进行连接（阻塞等待），成功连接返回 0，否则返回 SOCKET_ERROR
    if (connect(sockClient, (SOCKADDR *) &addrSrv, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        printf("Unable to connect to server: %ld\n", WSAGetLastError());
        close(sockClient);
        return;
    } else {
        printf("Connection successful\n");
    }

    // 发送消息。如果发送成功，返回发送成功的字节数，否则返回 SOCKET_ERROR
    if (send(sockClient, "hello", strlen("hello") + 1, 0) == SOCKET_ERROR) {
        printf("Send failed: %d\n", WSAGetLastError());
        close(sockClient);
        return;
    } else {
        printf("Send successful\n");
    }
    // 接收来自服务端的消息（阻塞等待），成功接收返回接收的字节数，正常关闭返回0，其余情况返回 SOCKET_ERROR
    iResult = recv(sockClient, recvBuf, 50, 0);
    if (iResult == SOCKET_ERROR) {
        printf("recv failed: %d\n", WSAGetLastError());
        close(sockClient);
        return;
    } else if (iResult == 0) {
        printf("Connection closed\n");
    } else{
        printf("Bytes received: %d\n", iResult);
        printf("Server reply:\n");
        printf("%s\n", recvBuf);
    }

    close(sockClient);
}



int main() {
    test_1();

    return 0;
}

