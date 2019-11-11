cmake_policy(SET CMP0074 NEW)

include(assign_source_group)

set(MODULE_NAME "application")

# Generate code from ui files
file(GLOB_RECURSE UI_FILES *.ui)
set(CMAKE_AUTOMOC ON) 
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# Generate rules for building source files from the resources
qt5_add_resources(QRCS "res/resources.qrc")

file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
file(GLOB_RECURSE HEADER_FILES *.hpp *.h)

link_directories(${NODE_EDITOR_LIBRARY_DIR})
include_directories(${JSON_INCLUDE_DIR} ${NODE_EDITOR_INCLUDE_DIR})

add_library(${MODULE_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES} ${UI_HEADERS} ${QRCS})

# Add the Qt5 Widgets for linking
target_link_libraries(${MODULE_NAME} Qt5::Widgets Qt5::Core ${NODE_EDITOR_LIBRARY})
target_link_directories(${MODULE_NAME} PUBLIC ${NODE_EDITOR_LIBRARY_DIR})

assign_source_group(${SOURCE_FILES} ${HEADER_FILES} ${UI_HEADERS} ${QRCS})

add_definitions(-DNODE_EDITOR_STATIC)
add_dependencies(${MODULE_NAME} ExternalDependencies)