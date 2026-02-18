cmake_minimum_required(VERSION 3.10)
project(dsapp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dsapp test/singly.cpp)

target_include_directories(dsapp PRIVATE ${PROJECT_SOURCE_DIR}/include)