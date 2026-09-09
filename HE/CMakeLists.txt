cmake_minimum_required(VERSION 4.2)
project(HE)

set(CMAKE_CXX_STANDARD 14)

add_executable(HE
        Hello_World.cpp)

set (A ON)
if(A)
    message(STATUS "A:${PROJECT_NAME}")
    message(STATUS "A:${PROJECT_SOURCE_DIR}")
    message(STATUS "A:${PROJECT_BINARY_DIR}")
endif()
