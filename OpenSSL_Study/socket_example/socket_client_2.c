/**
 * 一个简单的 http 客户端
 *
 * -- 功能介绍 -----------
 * 可以模拟浏览器发送 http 请求
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

    while (1) {
        char input[100];
        char send_data[1024] = {0};
        char recv_data[1024];
        int len;
        int count;
        int connection_flag = 1;

        printf("Input:");
        memset(input, '\0', 100);
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "blank") == 0) {

        } else if (strcmp(input, "get") == 0) {
            strcpy(send_data, "GET / HTTP/1.1\r\n\r\n");
        } else {
            strcpy(send_data, input);
        }

        len = BIO_write(cbio, send_data, strlen(send_data));
        if (len > 0) {
            printf("send success(len=%d):\n", len);
            printf("%s\n", send_data);
        } else if (len == -1) {
            printf("send failed(len=%d), socket closed by accident:\n", len);
            printf("%s\n", send_data);
            break;
        } else {
            printf("send failed(len=%d):\n", len);
            printf("%s\n", send_data);
            continue;
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
                connection_flag = 0;
                break;
            } else {
                printf("[ error(len=%d), connection has been closed ]\n", len);
                connection_flag = 0;
                break;
            }
        }

        if (connection_flag == 0) {
            break;
        }
    }

    // # 释放空间
    BIO_free_all(cbio);
    printf("disconnected\n");

    return 0;
}