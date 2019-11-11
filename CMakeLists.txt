cmake_minimum_required(VERSION 3.13)

cmake_policy(SET CMP0048 OLD)
project(nodeeditor)

cmake_policy(SET CMP0020 NEW)
cmake_policy(SET CMP0028 NEW)
cmake_policy(SET CMP0071 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APPLICATION_NAME node-editor)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/" ${CMAKE_MODULE_PATH} )

##
message("----------------")
message("CMAKE_PREFIX_PATH = {")
foreach (_path_var ${CMAKE_PREFIX_PATH})
  message("  ${_path_var}")
endforeach()
message("}")

message("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
include (get_all_cmake_args)
get_all_cmake_args(CL_ARGS)
message("CL_ARGS = {")
foreach (_cl_arg ${CL_ARGS})
  message("  ${_cl_arg}")
endforeach()
message("}")
message("----------------")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

if (NOT Qt5_DIR)
  include(kurva_anyad)
endif()
message("Qt5_DIR=${Qt5_DIR}")


SET(APPLICATION_SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/application")

add_subdirectory(thirdparty)

add_subdirectory(src)
add_subdirectory(tests)
