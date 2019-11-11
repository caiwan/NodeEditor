include (get_all_cmake_args)
get_all_cmake_args(CL_ARGS)

# include(${CMAKE_CURRENT_SOURCE_DIR}/nlohmann_json.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/nodeeditor.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/gtest.cmake)

add_custom_target(ExternalDependencies)
add_dependencies(ExternalDependencies
    nodeeditor
    googletest
)

set_target_properties(ExternalDependencies PROPERTIES FOLDER ExternalProjectTargets)
