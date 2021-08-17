#include<windows.h>
#include<stdio.h>

#define BUFFER_SIZE 1024 //1k
#define ACK_MESG_RECV "Message received successfully"
#define g_szPipeName "\\\\.\\Pipe\\MyNamedPipe"  //Name given to the pipe

int main(int argc, char *argv[]) {

    HANDLE hPipe;

    hPipe = CreateNamedPipe(
            g_szPipeName,             // pipe name
            PIPE_ACCESS_DUPLEX,       // read/write access
            PIPE_TYPE_MESSAGE |       // message type pipe
            PIPE_READMODE_MESSAGE |   // message-read mode
            PIPE_WAIT,                // blocking mode
            PIPE_UNLIMITED_INSTANCES, // max. instances
            BUFFER_SIZE,              // output buffer size
            BUFFER_SIZE,              // input buffer size
            NMPWAIT_USE_DEFAULT_WAIT, // client time-out
            NULL);                    // default security attribute

    if (INVALID_HANDLE_VALUE == hPipe) {
        printf("\nError occurred while creating the pipe: %d", GetLastError());
        exit(-1);  //Error
    } else {
        printf("CreateNamedPipe() was successful.\n");
    }


    // 等待客户端连接
    while (1) {
        printf("--------------------------------\n");
        printf("[info] waiting for client connection\n");
        BOOL bClientConnected = ConnectNamedPipe(hPipe, NULL);  // 一次只能接受一个连接吗？

        // 有没有办法获取连接的客户端信息？
        if (FALSE == bClientConnected) {
            printf("\nError occurred while connecting to the client: %d", GetLastError());
            CloseHandle(hPipe);
            exit(-2);
        } else {
            printf("[info] client connected\n");
        }

        char szBuffer[BUFFER_SIZE];
        DWORD cbBytes;

        //We are connected to the client.
        //To communicate with the client we will use ReadFile()/WriteFile()
        //on the pipe handle - hPipe

        // 读取客户端消息
        BOOL bResult = ReadFile(
                hPipe,                // handle to pipe
                szBuffer,             // buffer to receive data
                sizeof(szBuffer),     // size of buffer
                &cbBytes,             // number of bytes read
                NULL);                // not overlapped I/O

        if ((!bResult) || (0 == cbBytes)) {
            printf("\nError occurred while reading from the client: %d", GetLastError());
            CloseHandle(hPipe);
            exit(-3);
        } else {
            printf("[info] ReadFile() was successful.");
        }

        printf("[info] Client sent the following message:\n%s\n", szBuffer);

        strcpy(szBuffer, ACK_MESG_RECV);

        // 向客户端回复
        bResult = WriteFile(
                hPipe,                // handle to pipe
                szBuffer,             // buffer to write from
                strlen(szBuffer) + 1,   // number of bytes to write, include the NULL
                &cbBytes,             // number of bytes written
                NULL);                // not overlapped I/O

        if ((!bResult) || (strlen(szBuffer) + 1 != cbBytes)) {
            printf("\nError occurred while writing to the client: %d", GetLastError());
            CloseHandle(hPipe);
            return 1;  //Error
        } else {
            printf("[info] WriteFile() was successful.\n");
        }
        // 关闭连接
        DisconnectNamedPipe(hPipe);

        if (strcmp(szBuffer, "close") == 0) {
            break;
        }
    }

    // 关闭管道
    CloseHandle(hPipe);
    return 0;
}