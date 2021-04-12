/**
 * 一个简单的 http 客户端
 *
 * -- 功能介绍 -----------
 * 发送一个 http 请求给服务端后，
 * 立即接收来自服务端的消息，
 * 然后关闭连接
 */

#include "openssl/bio.h"
#include "applink.c"

#include <stdio.h>
#include <string.h>

int main() {
    BIO *cbio;

    // # 创建 con bio
    cbio = BIO_new_connect("127.0.0.1:80");



    // 进行连接
    printf("connecting...\n");
    if (BIO_do_connect(cbio) <= 0) {
        fprintf(stderr, "Error connecting to server!\n");
        exit(-2);
    }
    printf("connected\n");

    char send_data[1024] = {0};
    char recv_data[1024];
    int len;
    int count;


    strcpy(send_data, "GET / HTTP/1.1\r\n\r\n");

    len = BIO_write(cbio, send_data, strlen(send_data));
    if (len > 0) {
        printf("send success(len=%d):\n", len);
        printf("%s\n", send_data);
    } else if (len == -1) {
        printf("send failed(len=%d), socket closed by accident:\n", len);
        printf("%s\n", send_data);
    } else {
        printf("send failed(len=%d):\n", len);
        printf("%s\n", send_data);
    }

    // # 读取服务端响应
    printf("server response:\n");
    count = 0;
    while (1) {
        count++;
        memset(recv_data, '\0', 1024);
        len = BIO_read(cbio, recv_data, 1024);
        if (len > 0 && len < 1024) {
            printf("%s\n", recv_data);
            break;
        } else if (len == 1024){
            printf("[ count=%d(len=%d) ]\n", count, len);
            printf("%s\n", recv_data);
        } else if (len == 0) {
            printf("[ close(len=%d), connection closed normally]\n", len);
            break;
        } else {
            printf("[ error(len=%d), connection has been closed ]\n", len);
            break;
        }
    }

    // # 释放空间
    BIO_free(cbio);
    printf("disconnected\n");

    return 0;
}