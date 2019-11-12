include(ExternalProject)

SET(PREFIX googletest)
SET(GIT_URL https://github.com/google/googletest.git)
SET(GIT_TAG "9d4cde44a4a3952cf21861f9370b3bed9265dfd7")
# SET(GIT_TAG "release-1.8.1")

SET(GTEST_INSTALL_DIR ${CMAKE_BINARY_DIR}/externals/)

ExternalProject_Add(${PREFIX}
  GIT_REPOSITORY "${GIT_URL}"
  GIT_TAG "${GIT_TAG}"
  PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
  CMAKE_ARGS ${CL_ARGS} -DCMAKE_INSTALL_PREFIX=${GTEST_INSTALL_DIR} -DBUILD_SHARED_LIBS=ON -DCMAKE_DEBUG_POSTFIX=${CMAKE_DEBUG_POSTFIX}
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  TEST_COMMAND ""
  )

SET(GTEST_INCLUDE_DIR "${GTEST_INSTALL_DIR}/include" CACHE PATH "")

## TODO Probably we'll need just the libraries

## -- Windows
if (WIN32)
  # NOTE: MSVC only
  SET(GTEST_LIB_DIR "${GTEST_INSTALL_DIR}/lib" CACHE PATH "")
  SET(GTEST_BIN_DIR "${GTEST_INSTALL_DIR}/bin" CACHE PATH "")
  SET(GTEST_lib_suffix ".lib")
  SET(GTEST_bin_prefix "")
  SET(GTEST_bin_suffix ".dll")
endif (WIN32)

## -- Linux

if (UNIX AND NOT APPLE)
  SET(GTEST_LIB_DIR "${GTEST_INSTALL_DIR}/lib" CACHE PATH "")
  SET(GTEST_BIN_DIR "${GTEST_INSTALL_DIR}/lib" CACHE PATH "")
  SET(GTEST_lib_suffix "")
  SET(GTEST_bin_prefix "lib")
  SET(GTEST_bin_suffix ".so")
endif ()

## -- Apple

if (APPLE)
  SET(GTEST_LIB_DIR "${GTEST_INSTALL_DIR}/lib" CACHE PATH "")
  SET(GTEST_BIN_DIR "${GTEST_INSTALL_DIR}/lib" CACHE PATH "")
  SET(GTEST_lib_suffix "")
  SET(GTEST_bin_prefix "lib")
  SET(GTEST_bin_suffix ".dylib")
endif ()

# Glue it all together

if (GENERATOR_IS_MULTI_CONFIG)
  SET(GTEST_TEST_LIBRARY
    optimized gtest${CMAKE_RELEASE_POSTFIX}${GTEST_lib_suffix}
    debug gtest${CMAKE_DEBUG_POSTFIX}${GTEST_lib_suffix}
    optimized gtest_main${CMAKE_RELEASE_POSTFIX}${GTEST_lib_suffix}
    debug gtest_main${CMAKE_DEBUG_POSTFIX}${GTEST_lib_suffix}
    CACHE INTERNAL "" FORCE
    )

  SET(GTEST_MOCK_LIBRARY
    optimized gmock${CMAKE_RELEASE_POSTFIX}${GTEST_lib_suffix}
    debug gmock${CMAKE_DEBUG_POSTFIX}${GTEST_lib_suffix}
    optimized gmock_main${CMAKE_RELEASE_POSTFIX}${GTEST_lib_suffix}
    debug gmock_main${CMAKE_DEBUG_POSTFIX}${CMAKE_DEBUG_POSTFIX}${GTEST_lib_suffix}
    CACHE INTERNAL "" FORCE
    )

else ()
  string(TOUPPER ${CMAKE_BUILD_TYPE} _CMAKE_BUILD_TYPE)
  if (_CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    SET(GTEST_TEST_LIBRARY
      gtest${GTEST_lib_suffix}
      gtest_main${GTEST_lib_suffix}
      CACHE INTERNAL "" FORCE
      )
    SET(GTEST_MOCK_LIBRARY
      gmock${GTEST_lib_suffix}
      gmock_main${GTEST_lib_suffix}
      CACHE INTERNAL "" FORCE
      )
  endif ()
endif ()

SET(GTEST_BOTH_LIBRARIES ${GTEST_TEST_LIBRARY} ${GTEST_MOCK_LIBRARY} CACHE INTERNAL "" FORCE)

SET(GTEST_TEST_BINARY_RELEASE
  ${GTEST_BIN_DIR}/${GTEST_bin_prefix}gtest${GTEST_bin_suffix}
  ${GTEST_BIN_DIR}/${GTEST_bin_prefix}gtest_main${GTEST_bin_suffix}
  CACHE INTERNAL "" FORCE
  )

SET(GTEST_TEST_BINARY_DEBUG
  ${GTEST_BIN_DIR}/${GTEST_bin_prefix}gtest${CMAKE_DEBUG_POSTFIX}${GTEST_bin_suffix}
  ${GTEST_BIN_DIR}/${GTEST_bin_prefix}gtest_main${CMAKE_DEBUG_POSTFIX}${GTEST_bin_suffix}
  CACHE INTERNAL "" FORCE
  )

SET(GTEST_MOCK_BINARY_RELEASE
  ${GTEST_BIN_DIR}/${GTEST_bin_prefix}gmock${GTEST_bin_suffix}
  ${GTEST_BIN_DIR}/${GTEST_bin_prefix}gmock_main${GTEST_bin_suffix}
  CACHE INTERNAL "" FORCE
  )

SET(GTEST_MOCK_BINARY_DEBUG
  ${GTEST_BIN_DIR}/${GTEST_bin_prefix}gmock${CMAKE_DEBUG_POSTFIX}${GTEST_bin_suffix}
  ${GTEST_BIN_DIR}/${GTEST_bin_prefix}gmock_main${CMAKE_DEBUG_POSTFIX}${GTEST_bin_suffix}
  CACHE INTERNAL "" FORCE
  )

SET(GTEST_BOTH_BINARIES_RELEASE ${GTEST_TEST_BINARY_RELEASE} ${GTEST_MOCK_BINARY_RELEASE} CACHE INTERNAL "" FORCE)
SET(GTEST_BOTH_BINARIES_DEBUG ${GTEST_TEST_BINARY_DEBUG} ${GTEST_MOCK_BINARY_DEBUG} CACHE INTERNAL "" FORCE)
