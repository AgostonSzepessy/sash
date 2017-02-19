include(CMakeParseArguments)

function(add_unit_test)
	cmake_parse_arguments(UNIT_TEST "" "NAME" "SRCS;LIBS" ${ARGN})

	# Must specify a name for unit test
	if(NOT UNIT_TEST_NAME)
		message(FATAL_ERROR "Unit test must have a name!")
	endif(NOT UNIT_TEST_NAME)

	# Must specify at least one source file
        if(NOT UNIT_TEST_SRCS)
		message(FATAL_ERROR "Unit test must have a source file!")
        endif(NOT UNIT_TEST_SRCS)

	# By default, the tests are linked to Check
	if(NOT UNIT_TEST_LIBS)
		message(STATUS "No libraries specified; only linking with default ones")
	endif(NOT UNIT_TEST_LIBS)

	message(STATUS "Creating test: ${UNIT_TEST_NAME}")
	message(STATUS "Test sources are:")

	foreach(src ${UNIT_TEST_SRCS})
                message("- ${src}")
	endforeach(src)

	set(LIBS ${LIBS} ${CHECK_LIBRARIES} ${UNIT_TEST_LIBS})

	add_executable(${UNIT_TEST_NAME} ${UNIT_TEST_SRCS})
	target_link_libraries(${UNIT_TEST_NAME} ${LIBS})

        add_test(NAME ${UNIT_TEST_NAME} COMMAND $<TARGET_FILE:${UNIT_TEST_NAME}>)
endfunction(add_unit_test)
