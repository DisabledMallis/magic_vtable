cmake_minimum_required(VERSION 3.26)
project(constexpr_vtable)

set(CMAKE_CXX_STANDARD 23)

add_library(constexpr_vtable INTERFACE)
target_include_directories(constexpr_vtable INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

option(BUILD_CVFT_TESTS "Build tests" ON)
if(BUILD_CVFT_TESTS)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test)
endif ()