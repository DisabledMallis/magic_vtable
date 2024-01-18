cmake_minimum_required(VERSION 3.26)
project(magic_vtable)

set(CMAKE_CXX_STANDARD 23)

add_library(magic_vtable INTERFACE)
target_include_directories(magic_vtable INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

option(BUILD_MVFT_TESTS "Build tests" OFF)
if(BUILD_MVFT_TESTS)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test)
endif ()