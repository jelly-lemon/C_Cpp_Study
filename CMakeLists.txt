# cmake_minimum_required(VERSION <specify CMake version here>)
project(C_C++_Study)

set(CMAKE_CXX_STANDARD 11)

add_executable(912 912.c)

add_executable(str_study str_study.cpp)

add_executable(change_pointer c/change_pointer.c)

add_executable(thread_basic_create c/thread_basic_create.c)

add_executable(thread_mutex c/thread_mutex.c)