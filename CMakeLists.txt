cmake_minimum_required(VERSION 3.0)
project(1C)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${1C_SOURCE_DIR}/bin)

add_subdirectory(src)