cmake_minimum_required(VERSION 3.16)
project(cwk1 C)

set(CMAKE_C_STANDARD 11)

add_executable(cwk1 main.c book_management.h run_interface.c user.c manager.c run_interface.h book_management.c user.h manager.h utils.c utils.h)
