cmake_minimum_required(VERSION 2.8.11)

if (UNIX AND NOT APPLE)
	include_directories("${APPLICATION_SOURCE_PATH}")
	add_executable(${APPLICATION_NAME} "main.cpp")
	target_link_libraries(${APPLICATION_NAME} application)
endif()
