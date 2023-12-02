cmake_minimum_required(VERSION 3.26)
project(INF329A)

set(CMAKE_CXX_STANDARD 23)

add_executable(INF329A main.cpp
        list.h
        basic_ops.h
        basic_ops.cpp
        list_trans.h
        list_trans.cpp
        list.cpp
        list_red.h
        list_red.cpp
        list_search.h
        list_search.cpp
        list_sort.h
        list_sort.cpp
)

