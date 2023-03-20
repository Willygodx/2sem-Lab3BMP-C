cmake_minimum_required(VERSION 3.24)
project(Ruslan C)

set(CMAKE_C_STANDARD 90)

add_executable(Ruslan labStruct/main.c labStruct/functions.c labStruct/functions.h)
