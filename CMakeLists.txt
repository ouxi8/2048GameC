cmake_minimum_required(VERSION 3.29)
project(2048GameC C)

set(CMAKE_C_STANDARD 11)

add_executable(2048GameC main.c
        logic.c
        logic.h
        utils.c
        utils.h)
