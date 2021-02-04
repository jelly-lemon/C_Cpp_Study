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