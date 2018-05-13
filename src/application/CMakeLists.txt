cmake_minimum_required(VERSION 2.8.11)

set(MODULE_NAME "application")

file(GLOB_RECURSE UI_FILES *.ui)

set(CMAKE_AUTOMOC ON) 

# Generate code from ui files
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# Generate rules for building source files from the resources
qt5_add_resources(QRCS "res/resources.qrc")

file(GLOB_RECURSE SOURCE_FILES *.cpp)
file(GLOB_RECURSE HEADER_FILES *.h)

add_library(${MODULE_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES} ${UI_HEADERS} ${QRCS})

# Add the Qt5 Widgets for linking
target_link_libraries(${MODULE_NAME} Qt5::Widgets Qt5::Core nodes)

include_directories("${JSON_INCLUDE_DIR} ${NODES_INCLUDE_DIR}")

assign_source_group(${SOURCE_FILES} ${HEADER_FILES} ${UI_HEADERS} ${QRCS})
