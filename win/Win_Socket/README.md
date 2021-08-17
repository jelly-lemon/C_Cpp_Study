# Windows 环境下 Socket 网络编程

## 环境
编程 IDE：CLion
C++ 标准：C++ 11
编译器：MinGW （版本 w64 6.0）

# 疑难杂症
## undefined reference to `__imp_WSAStartup'
原因：
生成可执行文件时，链接器没有链接 wsock 静态库，需要人为指定。

解决：
在 CMakeList 中添加：target_link_libraries(Server ws2_32)
或者另外一种写法：target_link_libraries(Server wsock32.lib)
Server 是目标名，是前面语句自定义的（例如，add_executable(Server base_socket/server.cpp)）。

