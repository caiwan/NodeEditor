cmake_minimum_required(VERSION 2.8.11)

if (WIN32)
	add_executable(${APPLICATION_NAME} WIN32 "main.cpp")

	set_target_properties(${APPLICATION_NAME}
		PROPERTIES
			RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	)

	include_directories("${APPLICATION_SOURCE_PATH}")
	target_link_libraries(${APPLICATION_NAME} application)
endif()
