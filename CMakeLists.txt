cmake_minimum_required(VERSION 3.4.3)
project(sash)

SET(TESTS_ENABLED ON CACHE BOOLEAN "Build sash with tests")

set(C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if(TESTS_ENABLED)
    find_package(Check REQUIRED)
    enable_testing()
    add_subdirectory(${PROJECT_SOURCE_DIR}/test)
endif(TESTS_ENABLED)
