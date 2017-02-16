include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC_ROOT ${PROJECT_SOURCE_DIR}/src)
set(INC_ROOT ${PROJECT_SOURCE_DIR}/include)

set(SRC
	${SRC_ROOT}/main.c
	${SRC_ROOT}/util.c
	${INC_ROOT}/util.h)

add_executable(sash ${SRC})
