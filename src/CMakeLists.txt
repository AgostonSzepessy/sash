include_directories(${PROJECT_SOURCE_DIR}/include/sash)

set(SRC_ROOT ${PROJECT_SOURCE_DIR}/src)
set(INC_ROOT ${PROJECT_SOURCE_DIR}/include/sash)

set(SRC
	${SRC_ROOT}/main.c
	${SRC_ROOT}/builtins.c
	${INC_ROOT}/builtins.h
	${SRC_ROOT}/command.c
	${INC_ROOT}/command.h
	${SRC_ROOT}/input.c
	${INC_ROOT}/input.h
	${SRC_ROOT}/util.c
	${INC_ROOT}/util.h
	${INC_ROOT}/uthash.h
	${SRC_ROOT}/variable.c
	${INC_ROOT}/variable.h)

add_executable(sash ${SRC})
