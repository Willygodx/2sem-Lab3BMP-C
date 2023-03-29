cmake_minimum_required(VERSION 3.24)
project(decompr C)

set(CMAKE_C_STANDARD 99)

add_executable(decompr main.c functions.c functions.h)
