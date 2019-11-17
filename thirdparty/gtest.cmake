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

SET(GTEST_INCLUDE_DIR "${GTEST_INSTALL_DIR}/include" CACHE PATH "")

if (WIN32)
  # NOTE: MSVC only
  SET(_lib_dir "lib")
  SET(_lib_prefix "")
  SET(_lib_suffix ".lib")
  SET(_bin_dir "bin")
  SET(_bin_prefix "")
  SET(_bin_suffix ".dll")
elseif (UNIX AND NOT APPLE)
  SET(_lib_dir "lib")
  SET(_lib_prefix "")
  SET(_lib_suffix "lib")
  SET(_bin_prefix "")
  SET(_bin_suffix ".so")
elseif (APPLE)
  SET(_lib_dir "lib")
  SET(_lib_prefix "")
  SET(_lib_suffix "")
  SET(_bin_dir "lib")
  SET(_bin_prefix "")
  SET(_bin_suffix ".dylib")
endif ()

# Glue all together

if (GENERATOR_IS_MULTI_CONFIG)
  set(GTEST_LIBRARIES
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gtest${_lib_suffix}"
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gtest_main${_lib_suffix}")
  set(GMOCK_LIBRARIES
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gmock${_lib_suffix}"
    "${GTEST_INSTALL_DIR}/${_lib_dir}//${_lib_prefix}gmock_main${_lib_suffix}")
else (GENERATOR_IS_MULTI_CONFIG)
  set(GTEST_LIBRARIES
    debug
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gtest${CMAKE_DEBUG_POSTFIX}${_lib_suffix}"
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gtest_main${CMAKE_DEBUG_POSTFIX}${_lib_suffix}"
    optimized
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gtest${CMAKE_RELEASE_POSTFIX}${_lib_suffix}"
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gtest_main${CMAKE_RELEASE_POSTFIX}${_lib_suffix}")
  set(GMOCK_LIBRARIES
    debug
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gmock${CMAKE_DEBUG_POSTFIX}${_lib_suffix}"
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gmock_main${CMAKE_DEBUG_POSTFIX}${_lib_suffix}"
    optimized
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gmock${CMAKE_RELEASE_POSTFIX}${_lib_suffix}"
    "${GTEST_INSTALL_DIR}/${_lib_dir}/${_lib_prefix}gmock_main${CMAKE_RELEASE_POSTFIX}${_lib_suffix}")
endif (GENERATOR_IS_MULTI_CONFIG)

SET(GTEST_LIB_DIR "${GTEST_INSTALL_DIR}/${_lib_dir}" CACHE PATH "")
SET(GTEST_BIN_DIR "${GTEST_INSTALL_DIR}/${_bin_dir}" CACHE PATH "")
