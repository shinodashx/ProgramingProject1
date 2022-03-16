cmake_minimum_required(VERSION 3.21)
project(cwk1 C)

set(CMAKE_C_STANDARD 17)

add_executable(cwk1 main.c book_management.h run_interface.c user.c manager.c)
