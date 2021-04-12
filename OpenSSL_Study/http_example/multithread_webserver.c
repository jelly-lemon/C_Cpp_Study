/**
 * http_web_server 多线程版本
 */

#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <pthread.h>

#include "openssl/bio.h"
#include "openssl/err.h"
#include "applink.c"


void* thread_main(void *arg) {
    BIO *cbio = (BIO *)arg;

    while (1) {
        int len;
        int count;
        int all_flag = 0;

        // # 收取消息
        printf("recv:\n");
        count = 0;
        while (1) {
            count++;
            char data[1024];
            memset(data, '\0', 1024);
            len = BIO_read(cbio, data, 1024);
            if (0 < len) {
                if (len == 1024) {
                    printf("[count=%d(length=%d), still more data, continue receiving]\n", count, len);
                    printf("%s\n", data);
                } else {
                    printf("[count=%d(length=%d), client send all data, stop receiving]\n", count, len);
                    printf("%s\n", data);
                    all_flag = 1;
                    break;
                }
            } else {
                if (len == 0) {
                    printf("[close(length=%d), connection closed normally, stop receiving]\n", len);
                } else if(len == -1) {
                    printf("[error(length=%d), connection has been closed, stop receiving]\n", len);
                } else {
                    printf("[error(length=%d), stop receiving]\n", len);
                }
                break;
            }
        }
        printf("\n");

        if (len <= 0) {
            break;
        }

        // # 发送消息
        const char *header_content =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain;charset=utf8\r\n"
                "\r\n"
                "Hello world";
        len = BIO_puts(cbio, header_content);
        if (len > 0) {
            printf("send:\n%s\n", header_content);
        } else {
            printf("send failed(len=%d):\n%s\n", len, header_content);
        }

        if (all_flag == 1) {
            break;
        }
    }


    // # 释放空间，关闭本次连接
    BIO_free(cbio);
    printf("free connection\n");
    printf("--------------------------------\n");

    return NULL;
}

int main() {
    BIO *abio, *cbio;

    // # 创建 accept BIO
    // 必须要带 IP 地址。（"4444", ":4444", "*:4444"） 都尝试过，客户端无法连接
    abio = BIO_new_accept("127.0.0.1:80");
    // # 首次调用 BIO_do_accept，功能是创建监听 socket
    if (BIO_do_accept(abio) <= 0) {
        fprintf(stderr, "Error setting up accept\n");
        ERR_print_errors_fp(stderr);
        exit(-1);
    } else {
        char host_name[128];
        struct hostent *myhost = NULL;
        int i;

        printf("server info:\n");
        if (gethostname(host_name, sizeof(host_name)) < 0) {
            fprintf(stderr, "Error gethostname\n");
            exit(-2);
        }
        printf("%16s:%s\n", "host_name", host_name);
        if (!(myhost = gethostbyname(host_name))) {
            fprintf(stderr, "Error gethostbyname\n");
            exit(-3);
        }
        for (i = 0; myhost->h_addr_list[i]; i++) {
            printf("%16s:%s\n", "ip", inet_ntoa(*(struct in_addr *) myhost->h_addr_list[i]));
        }

        const char *name = BIO_get_accept_name(abio);
        const char *port = BIO_get_accept_port(abio);
        printf("accept:\n");
        printf("%16s:%s\n", "ip", name);
        printf("%16s:%s\n", "port", port);
    }

    while (1) {
        // # 等待连接
        printf("++++++++++++++++++++++++++++++++\n");
        printf("waiting for connection..\n");
        // 后面调用 BIO_do_accept 表示等待连接(阻塞)
        if (BIO_do_accept(abio) <= 0) {
            fprintf(stderr, "Error accepting connection\n");
            ERR_print_errors_fp(stderr);
            exit(-4);
        } else {
            const char *host = BIO_get_peer_name(abio);
            const char *port = BIO_get_peer_port(abio);
            printf("%s:%s connected\n", host, port);
        }

        // # 获取 connection BIO
        cbio = BIO_pop(abio);

        pthread_t t;
        pthread_create(&t, NULL, thread_main, (void *)cbio);
        pthread_detach(t);
    }
}