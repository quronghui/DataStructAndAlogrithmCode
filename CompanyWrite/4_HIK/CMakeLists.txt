cmake_minimum_required(VERSION 3.14)
project(4_HIK C)

set(CMAKE_C_STANDARD 11)

add_executable(main main.c)
add_executable(swap_value swap_value.c)
add_executable(type_convert type_convert.c)
add_executable(global_local_variable global_local_variable.c)

