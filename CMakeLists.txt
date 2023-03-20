cmake_minimum_required(VERSION 3.24)
project(sonar_scanner_example)

set(CMAKE_C_STANDARD 90)

add_executable(sonar_scanner_example labStruct/main.c labStruct/functions.c labStruct/functions.h)
