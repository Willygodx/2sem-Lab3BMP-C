cmake_minimum_required(VERSION 3.24)
project(ruslan)

set(CMAKE_C_STANDARD 90)

add_executable(ruslan labStruct/main.c labStruct/functions.c labStruct/functions.h)
