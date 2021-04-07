# 指定 CMake 最低版本要求
cmake_minimum_required(VERSION 2.8)

# 指定项目名
project(C_Cpp_Study)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# c 标准
set(CMAKE_C_STANDARD 11)

# 打印信息
message("CMAKE_EXE_LINKER_FLAGS=" ${CMAKE_EXE_LINKER_FLAGS})
message("CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
message("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
message("CMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}")
message("CMAKE_C_STANDARD=${CMAKE_C_STANDARD}")
message("CXX_DEFINES=${CXX_DEFINES}")
message("CXX_INCLUDES=${CXX_INCLUDES}")
message("CXX_FLAGS=${CXX_FLAGS}")

# 指定可用头文件目录
include_directories(include/my_gtest1.10)

# 指定可用链接库目录
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/my_gtest1.10) # link_directories 不能用相对路径

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
add_executable(fast_slow_pointer c/algorithm_study/fast_slow_pointer.c)

add_executable(global_variable c/global_init/global_variable.cpp)

add_executable(hash_table c/hash_table.c)

add_executable(const_test c/const_test.c)

add_executable(c_or_cpp c/c_or_cpp.c)

add_executable(words_reverse c/algorithm_study/words_reverse.c)

add_executable(string Cpp/string.cpp)

add_executable(macro c/macro.c)

add_executable(basic_data_type c/basic_data_type.c)

# 我觉得 add_executable 两个参数应该调换一下位置，用起来才方便

add_executable(clear_number_3rd c/algorithm_study/set_3rd_number.c)

add_executable(use_error Cpp/use_error.c)

add_executable(shared_pointer Cpp/shared_pointer.cpp)


add_executable(sample_linked_list Cpp/list_study.cpp)

add_executable(tranverse_tree c/algorithm_study/tranverse_tree.c)


add_executable(messagebox win32/messagebox.cpp)

add_executable(1 wmi/1.cpp)
# target_link_libraries(1 wbemuuid.lib)

add_executable(socket_server Win_Socket/base_socket/socket_server.c)
target_link_libraries(socket_server wsock32.lib)

add_executable(socket_client Win_Socket/base_socket/socket_client.c)
target_link_libraries(socket_client wsock32.lib)

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
# 链接 libgtest_main_w64-6.0.a 会出现 undefined reference to `testing::Message::Message()'
target_link_libraries(gtest_study libgtest.a)

add_executable(print_format c/print_format.c)

add_executable(thread_study c/thread_example/thread_study.c)

add_executable(control_cpu_ratio c/algorithm_study/control_cpu_ratio.c)

add_executable(time_study c/time_study.c)

add_executable(math_study c/math_study.c)

add_executable(tell_me_which_std c/tell_me_which_std.c)

add_executable(sort Cpp/sort.cpp)
target_link_libraries(sort libgtest.a)

add_executable(str_format Cpp/str_format.cpp)

add_executable(dos_query Win_Socket/base_socket/dos_query.c)
target_link_libraries(web_server wsock32.lib)


add_executable(minimal_exe c/minimal_exe.c)

add_executable(reverse_linkedlist Cpp/reverse_linkedlist.cpp)

add_executable(binary_one_number Cpp/binary_one_number.cpp)
target_link_libraries(binary_one_number libgtest.a)


add_executable(cmake_test_1 c/cmake_test/1.c)

add_executable(cpp_thread Cpp/cpp_thread.cpp)

add_executable(thread_error c/thread_example/thread_error.c)

add_executable(empty_class_size Cpp/empty_class_size.cpp)

add_executable(read_write_lock c/thread_example/read_write_lock.c)

add_executable(async_log c/thread_example/async_log.c)

add_executable(mutual_include Cpp/mutual_include.cpp)

add_executable(map_study Cpp/map_study.cpp)

add_executable(how_member_obejct_init Cpp/how_member_obejct_init.cpp)

add_executable(file_study Cpp/file_study.cpp)

add_executable(static_study Cpp/static_study.cpp)

add_executable(hello c/hello.c)

add_executable(hello_cpp Cpp/hello_cpp.cpp)