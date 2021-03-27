/**
 * 服务端简单的 socket 使用
 */

#include <stdio.h>
#include <winsock2.h>
#include <inaddr.h>
// #pragma comment(lib, "wsock32.lib") // 需要在 CMakLists 中隐式链接才行
int main() {
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    // 指定 socket 版本 1.1
    wVersionRequested = MAKEWORD(1, 1);

    // 加载指定版本的 socket 库
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        exit(-1);
    }

    // 如果加载失败
    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
        WSACleanup();
        exit(-1);
    }

    // 创建监听 socket
    SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);   // htonl 将主机数转换成无符号长整型的网络字节顺序。
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(6000);
    bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
    listen(sockSrv, 5); // 监听是否有请求，非阻塞

    SOCKADDR_IN addrClient;
    int len = sizeof(SOCKADDR);
    while (1) {
        // 等待连接
        SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);    // 没有客户端请求就会阻塞，有就接受
        char sendBuf[50];
        sprintf(sendBuf, "Welcome %s to here!", inet_ntoa(addrClient.sin_addr));    // inet_ntoa 将网络地址转换成“.”点隔的字符串格式
        send(sockConn, sendBuf, strlen(sendBuf)+1, 0);  // 向客户端发送请求
        char recvBuf[50];

        int n = recv(sockConn, recvBuf, 50, 0); // 接收来自客户端的内容
        printf("%s said:\n", inet_ntoa(addrClient.sin_addr));
        recvBuf[n] = '\0';
        printf("%s\n", recvBuf);
        closesocket(sockConn);  // 关闭与该客户端的socket连接
    }

}
