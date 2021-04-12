/*
 * socket BIO 客户端
 *
 * 程序功能：连接指定服务端，向服务端发送一条消息，读取来自服务端的消息，关闭连接
 * 和 socket_bio_server.cpp 配套使用，先运行 socket_bio_server.cpp，再运行该 socket_bio_client.cpp
 *
 * 基于 TCP的。没有使用应用层的任何协议，因为只有简单的读写操作。
 */


#include <stdio.h>
#include <cstring>

#include "openssl/err.h"
#include "openssl/bio.h"


int main() {
    BIO *cbio;
    int len;
    char data[1024];

    // # 创建 connect BIO
    cbio = BIO_new_connect("127.0.0.1:4444");

    // # 进行连接
    if (BIO_do_connect(cbio) <= 0) {
        exit(-1);
    }

    // # 向服务端发送信息
    BIO_puts(cbio, "I'm client, I want to talk with you...");

    // # 读取服务端消息
    while (1) {
        memset(data, '\0', 1024);
        len = BIO_read(cbio, data, 1024);
        if (len > 0) {
            printf("server said: %s\n", data);
        } else {
            printf("len=%d\n");
            break;
        }
    }

    // # 释放 connetion BIO
    BIO_free(cbio);

    return 0;

}