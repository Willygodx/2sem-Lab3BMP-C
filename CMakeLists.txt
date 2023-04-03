cmake_minimum_required(VERSION 3.24)
project(ruslan)

set(CMAKE_C_STANDARD 99)

add_executable(ruslan labBMP75248/main.c labBMP75248/functions.c labBMP75248/functions.h)
