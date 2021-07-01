# CMake 设置
cmake_minimum_required(VERSION 2.8) # 指定 CMake 最低版本要求
project(C_Cpp_Study) # 指定项目名
set(CMAKE_CXX_STANDARD 11)  # 指定 C++ 标准
set(CMAKE_C_STANDARD 11)    # c 标准
# set(CMAKE_CXX_FLAGS "-static ${CMAKE_CXX_FLAGS}")   # 强制静态链接

# 编译选项
#add_compile_options(-fno-elide-constructors) # 取消编译优化（MSVC不支持）

# 打印信息
#message("CMAKE_EXE_LINKER_FLAGS=${CMAKE_EXE_LINKER_FLAGS}")
#message("CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
#message("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
#message("CMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}")
#message("CMAKE_C_STANDARD=${CMAKE_C_STANDARD}")
#message("CXX_DEFINES=${CXX_DEFINES}")
#message("CXX_INCLUDES=${CXX_INCLUDES}")
#message("CXX_FLAGS=${CXX_FLAGS}")

# 依赖设置
# gtest
include_directories(include/my_gtest1.10)   # 依赖头文件
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib) # 链接库目录，link_directories 不能用相对路径
# openssl
include_directories(C:\\OpenSSL-Win64\\include) # 头文件夹
include_directories(include/my_openssl1.1.0g)   # applink.c
link_directories(C:\\OpenSSL-Win64\\lib)        # 库文件夹

# 运行目标
add_executable(delete_study Cpp/delete_study.cpp)
#add_executable(circular_reference Cpp/circular_reference.cpp)
add_executable(intellijent_pointer Cpp/intellijent_pointer.cpp)
add_executable(thread_study_c11 Cpp/thread_study_c11.cpp)
#add_executable(constructor_study Cpp/constructor_study.cpp)
#add_executable(log_study Cpp/log_study.cpp)
#add_executable(IOCP_client Win_Socket/IOCP/IOCP_client.cpp)
#target_link_libraries(IOCP_client ws2_32.lib)
#add_executable(IOCP_server Win_Socket/IOCP/IOCP_server.cpp)
#target_link_libraries(IOCP_server ws2_32.lib)
#add_executable(return_study Cpp/return_study.cpp)
#add_executable(NC136 Cpp/newcoder/to_do/NC136.cpp)
#add_executable(reg_study Cpp/reg_study.cpp)
#add_executable(select_study Win_Socket/select/select_study.c)
#add_executable(NC83 Cpp/newcoder/NC83.cpp)
#add_executable(NC145 Cpp/newcoder/NC145.cpp)
#add_executable(NC59 Cpp/newcoder/NC59.cpp)
#add_executable(hash_table_study Cpp/hash_table_study.cpp)
add_executable(reference_study Cpp/reference_study.cpp)
#add_executable(int_overflow Cpp/int_overflow.cpp)
#add_executable(queue_study Cpp/queue_study.cpp)
#add_executable(NC3 Cpp/newcoder/NC3.cpp)
#add_executable(NC73 Cpp/newcoder/NC73.cpp)
#add_executable(NC17 Cpp/newcoder/NC17.cpp)
#add_executable(NC52 Cpp/newcoder/NC52.cpp)
#add_executable(set_study Cpp/set_study.cpp)
#add_executable(printf_sleep c/printf_sleep.c)
#add_executable(NC61 Cpp/newcoder/NC61.cpp)
#add_executable(minimal_k_number Cpp/algorithm_study/minimal_k_number.cpp)
#add_executable(explicitly_study Cpp/explicitly_study.cpp)
#add_executable(min_heap_study Cpp/min_heap_study.cpp)
#add_executable(tx_0418_2 Cpp/leetcode/tx_0418_2.cpp)
#add_executable(tx_0418_1 Cpp/leetcode/tx_0418_1.cpp)
#add_executable(two_D_array Cpp/arr_study.cpp)
#add_executable(min_neighbor_diff Cpp/algorithm_study/min_neighbor_diff.cpp)
#add_executable(ali_0416_2 Cpp/leetcode/ali_0416_2.cpp)
#add_executable(ali_0416_1 Cpp/leetcode/ali_0416_1.cpp)
#add_executable(mem_bio OpenSSL_Study/base_BIO_example/mem_bio.c)
#target_link_libraries(mem_bio libcrypto)
##add_executable(file_bio OpenSSL_Study/base_BIO_example/file_bio.cpp)  # 编译目标
##target_link_libraries(file_bio openssl libssl libcrypto )  # OpenSSL 相关的库
##add_executable(base64_encode c/base64_encode.c)
#add_executable(912 c/leetcode/912.c)
#add_executable(str_study Cpp/str_study.cpp)
##add_executable(change_pointer c/change_pointer.c)
##add_executable(byte_alignment c/byte_alignment.c)
##add_executable(big_number c/big_number.c)
#add_executable(variable_arg c/variable_arg.c)
##add_executable(for_char c/for_char.c)
##add_executable(write_file c/write_file.c)
#add_executable(thread_basic_create c/thread_example/thread_basic_create.c)
##add_executable(thread_mutex c/thread_example/thread_mutex.c)
##add_executable(thread_scanf c/thread_example/thread_scanf.c)
add_executable(test test.cpp)
##add_executable(643 c/leetcode/643.c)
##add_executable(1208 c/leetcode/1208.c)
##add_executable(fast_slow_pointer c/algorithm_study/fast_slow_pointer.c)
##add_executable(global_variable c/global_init/global_variable.cpp)
##add_executable(hash_table c/hash_table.c)
#add_executable(const_study c/const_study.c)
##add_executable(c_or_cpp c/c_or_cpp.c)
##add_executable(words_reverse c/algorithm_study/words_reverse.c)
##add_executable(string Cpp/string.cpp)
##add_executable(macro c/macro.c)
#add_executable(basic_data_type c/basic_data_type.c)
### 我觉得 add_executable 两个参数应该调换一下位置，用起来才方便
##add_executable(clear_number_3rd c/algorithm_study/set_3rd_number.c)
##add_executable(use_error Cpp/use_error.c)
##add_executable(shared_pointer Cpp/shared_pointer.cpp)
#add_executable(list_study Cpp/list_study.cpp)
##add_executable(tranverse_tree c/algorithm_study/tranverse_tree.c)
##add_executable(messagebox win32/messagebox.cpp)
##add_executable(1 wmi/1.cpp)
### target_link_libraries(1 wbemuuid.lib)
##add_executable(socket_server Win_Socket/sample_socket/socket_server.c)
##target_link_libraries(socket_server wsock32.lib)
##add_executable(socket_client Win_Socket/sample_socket/socket_client.c)
##target_link_libraries(socket_client wsock32.lib)
##add_executable(web_server Win_Socket/web_server/http_web_server.c)
##target_link_libraries(web_server wsock32.lib)
##add_executable(pipe_server Win_Socket/namedpipe/pipe_server.c)
##add_executable(pipe_client Win_Socket/namedpipe/pipe_client.c)
##add_executable(ano_pipe_server Win_Socket/AnonymousPipes/ano_pipe_server.c)
#add_executable(overload_operators Cpp/overload_operators.cpp)
#add_executable(override_study Cpp/override_study.cpp)
#add_executable(vector_study Cpp/vector_study.cpp)
##add_executable(gtest_study Cpp/gtest_study.cpp)
### 静态链接库
### 链接 libgtest_main_w64-6.0.a 会出现 undefined reference to `testing::Message::Message()'
##target_link_libraries(gtest_study libgtest.a)
#add_executable(print_format c/print_format.c)
#add_executable(thread_study c/thread_example/thread_study.c)
#add_executable(control_cpu_ratio c/algorithm_study/control_cpu_ratio.c)
##add_executable(time_study c/time_study.c)
##add_executable(math_study c/math_study.c)
##add_executable(tell_me_which_std c/tell_me_which_std.c)
##add_executable(sort Cpp/algorithm_study/sort.cpp)
##target_link_libraries(sort libgtest.a)
#add_executable(str_format Cpp/str_format.cpp)
##add_executable(dos_query Win_Socket/sample_socket/dos_query.c)
##target_link_libraries(web_server wsock32.lib)
##add_executable(minimal_exe c/minimal_exe.c)
##add_executable(reverse_linkedlist Cpp/algorithm_study/reverse_linkedlist.cpp)
##add_executable(binary_one_number Cpp/algorithm_study/binary_one_number.cpp)
##target_link_libraries(binary_one_number libgtest.a)
##add_executable(cmake_test_1 c/cmake_test/1.c)
##add_executable(cpp_thread Cpp/cpp_thread.cpp)
##add_executable(thread_error c/thread_example/thread_error.c)
##add_executable(empty_class_size Cpp/empty_class_size.cpp)
##add_executable(read_write_lock c/thread_example/read_write_lock.c)
##add_executable(async_log c/thread_example/async_log.c)
##add_executable(mutual_include Cpp/mutual_include.cpp)
#add_executable(map_study Cpp/map_study.cpp)
#add_executable(how_member_obejct_init Cpp/how_member_obejct_init.cpp)
#add_executable(file_study Cpp/file_study.cpp)
##add_executable(static_study Cpp/static_study.cpp)
##add_executable(hello c/hello.c)
##add_executable(hello_cpp Cpp/hello_cpp.cpp)
##add_executable(delete_list_node Cpp/algorithm_study/delete_list_node.cpp)
### STATIC 生成 lib
### SHARED 生成 DLL
##add_library(my_dll SHARED c/dll_study/my_dll.c) # 咋会生成 libmy_dll.dll 和 lib123.a ？后面这个是什么东西？
##add_executable(load_dll c/dll_study/load_dll.c)
##add_executable(main_args c/main_args.c)
