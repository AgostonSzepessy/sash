cmake_minimum_required(VERSION 3.4.3)
project(sash)

set(C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
