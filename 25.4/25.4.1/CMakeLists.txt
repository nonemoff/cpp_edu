set(INCDIR = "${CMAKE_CURRENT_SOURCE_DIR}/include")
cmake_minimum_required(VERSION 3.5)

project(program)

include_directories(${INCDIR})

add_subdirectory(src)
