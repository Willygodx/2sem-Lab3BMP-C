cmake_minimum_required(VERSION 3.24)
project(ruslan)

set(CMAKE_C_STANDARD 99)

add_executable(ruslan decompr/main.c decompr/functions.c decompr/functions.h)
