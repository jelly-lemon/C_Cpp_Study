cmake_minimum_required(VERSION 2.8)
project(C_Cpp_Study)

set(CMAKE_CXX_STANDARD 11)

# 指定使用 c++11
# SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")

include_directories(include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)


add_executable(912 c/leetcode/912.c)

add_executable(str_study Cpp/str_study.cpp)

add_executable(change_pointer c/change_pointer.c)

add_executable(byte_alignment c/byte_alignment.c)

add_executable(big_number c/big_number.c)

add_executable(variable_arg c/variable_arg.c)

add_executable(for_char c/for_char.c)

add_executable(write_file c/write_file.c)

add_executable(thread_basic_create c/thread_example/thread_basic_create.c)

add_executable(thread_mutex c/thread_example/thread_mutex.c)

add_executable(thread_scanf c/thread_example/thread_scanf.c)

add_executable(test test.c)
#target_link_libraries(test Xinput.lib)

add_executable(643 c/leetcode/643.c)

add_executable(1208 c/leetcode/1208.c)
add_executable(fast_slow_pointer c/algorithm_example/fast_slow_pointer.c)

add_executable(global_variable c/global_init/global_variable.cpp)

add_executable(hash_table c/hash_table.c)

add_executable(const_test c/const_test.c)

add_executable(c_or_cpp c/c_or_cpp.c)

add_executable(words_reverse c/algorithm_example/words_reverse.c)

add_executable(string Cpp/string.cpp)

add_executable(macro c/macro.c)

add_executable(basic_data_type c/basic_data_type.c)

# 我觉得 add_executable 两个参数应该调换一下位置，用起来才方便

add_executable(style_input_output c/style_input_output.c)

add_executable(clear_number_3rd c/clear_number_3rd.c)

add_executable(use_error Cpp/use_error.c)

add_executable(shared_pointer Cpp/shared_pointer.cpp)


add_executable(sample_linked_list Cpp/list_study.cpp)

add_executable(tranverse_tree c/binary_tree/tranverse_tree.c)


add_executable(messagebox win32/messagebox.cpp)

add_executable(1 wmi/1.cpp)
# target_link_libraries(1 wbemuuid.lib)





add_executable(socket_server Win_Socket/base_socket/socket_server.cpp)
#target_link_libraries(socket_server wsock32.lib)

add_executable(Client Win_Socket/base_socket/socket_client.cpp)
target_link_libraries(Client wsock32.lib)

add_executable(web_server Win_Socket/web_socket/http_web_server.c)
target_link_libraries(web_server wsock32.lib)

add_executable(pipe_server Win_Socket/namedpipe/pipe_server.c)

add_executable(pipe_client Win_Socket/namedpipe/pipe_client.c)

add_executable(ano_pipe_server Win_Socket/AnonymousPipes/ano_pipe_server.c)

add_executable(overload_operators Cpp/overload_operators.cpp)

add_executable(override_study Cpp/override_study.cpp)

add_executable(vector_study Cpp/vector_study.cpp)

add_executable(gtest_study Cpp/gtest_study.cpp)
# 静态链接库
target_link_libraries(gtest_study gtest)
