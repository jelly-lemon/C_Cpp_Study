/**
 * 服务端简单的 socket 使用
 */

#include <stdio.h>
#include <winsock2.h>
#include <inaddr.h>

int main() {
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD(1, 1);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        exit(-1);
    }

    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
        WSACleanup();
        exit(-1);
    }

    SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);   // htonl 将主机数转换成无符号长整型的网络字节顺序。
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(80);
    bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
    listen(sockSrv, 5); // 监听是否有请求，非阻塞

    // 打印服务端信息
    char host_name[128];
    struct hostent *myhost = NULL;
    printf("server info:\n");
    if (gethostname(host_name, sizeof(host_name)) < 0) {
        fprintf(stderr, "Error gethostname\n");
        exit(-2);
    }
    printf("%16s:%s\n", "host_name", host_name);
    if(!(myhost = gethostbyname(host_name)))
    {
        fprintf(stderr, "Error gethostbyname\n");
        exit(-3);
    }
    int i;
    for (i = 0; myhost->h_addr_list[i]; i++) {
        printf("%16s:%s\n", "ip", inet_ntoa(*(struct in_addr*)myhost->h_addr_list[i]));
    }

    const char *name = BIO_get_accept_name(abio);
    const char *port = BIO_get_accept_port(abio);
    printf("accept:\n");
    printf("%16s:%s\n", "ip", name);
    printf("%16s:%s\n", "port", port);

    char serv_ip[20];
    inet_ntop(AF_INET, &addrSrv.sin_addr, serv_ip, sizeof(serv_ip));

    SOCKADDR_IN addrClient;
    int len = sizeof(SOCKADDR);
    while (1) {
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
