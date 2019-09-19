include (ExternalProject)

SET(PREFIX nlohmann_json)
SET(GIT_URL https://github.com/nlohmann/json.git)
SET(GIT_TAG v3.6.1)

SET(JSON_INSTALL_DIR ${CMAKE_BINARY_DIR}/externals/ CACHE PATH "" FORCE)

ExternalProject_Add(${PREFIX}
  GIT_REPOSITORY ${GIT_URL}
  GIT_TAG ${GIT_TAG}
  PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  CMAKE_ARGS -DJSON_BuildTests=OFF -DJSON_MultipleHeaders=OFF -DCMAKE_INSTALL_PREFIX=${JSON_INSTALL_DIR}
  TEST_COMMAND ""
)

SET(JSON_INCLUDE_DIR ${JSON_INSTALL_DIR}/include CACHE PATH "")

