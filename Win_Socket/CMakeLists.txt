cmake_minimum_required(VERSION 3.13)
project(Win_Socket)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server base_socket/socket_server.cpp)
target_link_libraries(Server wsock32.lib)

add_executable(Client base_socket/socket_client.cpp)
target_link_libraries(Client wsock32.lib)

add_executable(web_server web_socket/http_web_server.c)
target_link_libraries(web_server wsock32.lib)

add_executable(pipe_server namedpipe/pipe_server.c)

add_executable(pipe_client namedpipe/pipe_client.c)

add_executable(ano_pipe_server AnonymousPipes/ano_pipe_server.c)

add_executable(test test.c)

