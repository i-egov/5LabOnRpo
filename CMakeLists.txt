cmake_minimum_required(VERSION 3.17)
project(5LabOnRpo C)

set(CMAKE_C_STANDARD 99)

include_directories(util)

add_executable(5LabOnRpo
        util/file.c
        util/dynamicString.c
        menu.c
        main.c)
