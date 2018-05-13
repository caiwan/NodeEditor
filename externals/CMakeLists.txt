SET(JSON_BuildTests OFF)
SET(BUILD_TESTING OFF)
SET (BUILD_EXAMPLES OFF)

add_subdirectory(json)
add_subdirectory(nodeeditor)

set_target_properties(nodes PROPERTIES FOLDER externals)

SET(JSON_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/json")
SET(NODES_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/nodeeditor")

