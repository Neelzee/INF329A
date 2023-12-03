cmake_minimum_required(VERSION 3.26)
project(INF329A)

set(CMAKE_CXX_STANDARD 23)

include_directories(${PROJECT_SOURCE_DIR}/list_ops)

add_executable(INF329A main.cpp
        list.h
        conv/list_con.h
        conv/list_con.cpp
        list_ops/list_ops.h
        list_ops/list_ops.cpp
        sfolds/sfolds.h
        subl/subl.h
        search/searchl.h
        zipping/zip.h
        subl/subl.cpp
        zipping/zip.cpp
        sfolds/sfolds.cpp
        scans/scans.h
        scans/scans.cpp
        search/searchl.cpp
)

