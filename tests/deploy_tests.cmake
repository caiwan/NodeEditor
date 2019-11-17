
# --- Test environment deployment
set(TEST_DEPLOY_DIR ${CMAKE_BINARY_DIR}/tests/environment)

add_custom_target(${DEPLOY_TESTS})
set_target_properties(${DEPLOY_TESTS} PROPERTIES FOLDER tests)

if (WIN32)
  add_custom_command(
    TARGET ${DEPLOY_TESTS} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Qt5::Core> $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE:Qt5::Gui>
    ${TEST_DEPLOY_DIR}
  )
endif (WIN32)
set_target_properties(${DEPLOY_TESTS} PROPERTIES FOLDER tests)
