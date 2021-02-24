# 命名管道
我想在服务端获取连接管道的客户端是谁，有办法吗？知道客户端进程名和进程号就好了


# Server 端

代码流程：

1、创建命名管道：CreateNamedPipe

2、等待客户端连接：ConnectNamedPipe

3、读取客户端请求数据：ReadFile

4、向客户端回复数据：WriteFile

5、关闭连接：DisconnectNamedPipe

6、关闭管道：CloseHandle

# Client 端
