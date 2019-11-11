
# --- Test environment deployment
set(TEST_DEPLOY_DIR ${CMAKE_BINARY_DIR}/tests/environment)

add_custom_target(${DEPLOY_TESTS})
set_target_properties(${DEPLOY_TESTS} PROPERTIES FOLDER tests)

# -- If you have files to copy

#if (MSVC)
#   set_source_files_properties(
#       # WHATEVER FILES YOU PUT HERE
#       PROPERTIES VS_TOOL_OVERRIDE "None")
#endif(MSVC)

#include(copy_static_files)
#include(assign_source_group)

# copy_static_files(${DEPLOY_TEST}
# WHATEVER FILES YOU HAVE
#)

#assign_source_group(${ANIMATION_FILES} ${TEXTURE_FILES} ${MODEL_FILES} ${SHADER_FILES} ${JSON_FILES} ${MUSIC_FILES})
#assign_custom_source_group(SOURCE_GRP "Resource Files" IN_FILES ${MODEL_FILES})

if (WIN32)
  add_custom_command(
    TARGET ${DEPLOY_TESTS} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Qt5::Core> $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE:Qt5::Gui>
    ${TEST_DEPLOY_DIR}
  )
endif (WIN32)
set_target_properties(${DEPLOY_TESTS} PROPERTIES FOLDER tests)
