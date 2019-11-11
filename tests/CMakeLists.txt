enable_testing()

include(GoogleTest)

# ---
set(DEPLOY_TESTS DeployTests)
include("deploy_tests.cmake")
# ---

set(TEST_TARGET UnitTests)

file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
file(GLOB_RECURSE HEADER_FILES *.hpp *.h *.hh)

include_directories("${GTEST_INCLUDE_DIR}")
include_directories("${APPLICATION_SOURCE_PATH}")

add_executable(${TEST_TARGET} EXCLUDE_FROM_ALL ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${TEST_TARGET} application ${GTEST_BOTH_LIBRARIES})
set_target_properties(${TEST_TARGET} PROPERTIES FOLDER tests)

# gtest_add_tests(TARGET ${TEST_TARGET} WORKING_DIRECTORY ${TEST_DEPLOY_DIR} TEST_PREFIX old: TEST_EXECUTOR CTest)
# gtest_discover_tests(${TEST_TARGET} WORKING_DIRECTORY ${TEST_DEPLOY_DIR} TEST_PREFIX new: TEST_EXECUTOR CTest)

if (MSVC)
  # set_target_properties(${TEST_TARGET} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${TEST_DEPLOY_DIR}")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /DGTEST_LINKED_AS_SHARED_LIBRARY=1")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DGTEST_LINKED_AS_SHARED_LIBRARY=1")
endif (MSVC)

add_test(NAME Tests COMMAND ${TEST_TARGET} WORKING_DIRECTORY ${TEST_DEPLOY_DIR})

add_dependencies(${TEST_TARGET} ${DEPLOY_TESTS})
