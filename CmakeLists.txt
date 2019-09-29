cmake_minimum_required(VERSION 3.13)

project(nodeeditor)

cmake_policy(SET CMP0020 NEW)
cmake_policy(SET CMP0028 NEW)
cmake_policy(SET CMP0071 NEW)

set(APPLICATION_NAME node-editor)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH} )

if (QT5DIR)
  set(Qt5_DIR "${QT5DIR}/lib/cmake/Qt5" CACHE PATH "")
endif(QT5DIR)

message("----------------")
message("CMAKE_PREFIX_PATH = {")
foreach (_path_var ${CMAKE_PREFIX_PATH})
  message("  ${_path_var}")
endforeach()
message("}")

message("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
message("----------------")

include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/assign_source_group.cmake)
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/add_framework.cmake)
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/exclude_files.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)

SET(APPLICATION_SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/application")

add_subdirectory(thirdparty)

add_subdirectory(src)
add_subdirectory(tests)
