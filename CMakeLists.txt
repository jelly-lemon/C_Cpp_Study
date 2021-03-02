# cmake_minimum_required(VERSION <specify CMake version here>)
project(C_C++_Study)

set(CMAKE_CXX_STANDARD 11)

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

add_executable(use_linked_list Cpp/use_linked_list.cpp)

add_executable(sample_linked_list Cpp/sample_linked_list.cpp)

add_executable(tranverse_tree c/binary_tree/tranverse_tree.c)


add_executable(messagebox win32/messagebox.cpp)