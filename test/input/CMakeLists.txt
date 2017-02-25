set(TEST_ROOT ${CMAKE_SOURCE_DIR}/test/input)
set(SRC_ROOT ${CMAKE_SOURCE_DIR}/src)
set(INC_ROOT ${CMAKE_SOURCE_DIR}/include/sash)

include_directories(${CMAKE_SOURCE_DIR}/include)

include(Functions)

add_unit_test(NAME input_test SRCS ${TEST_ROOT}/input_test.c ${SRC_ROOT}/util.c ${SRC_ROOT}/input.c)
