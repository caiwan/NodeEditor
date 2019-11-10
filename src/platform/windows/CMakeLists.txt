if (WIN32)
	add_executable(${APPLICATION_NAME} WIN32 "main.cpp")

	set_target_properties(${APPLICATION_NAME}
		PROPERTIES
			RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	)

	include_directories("${APPLICATION_SOURCE_PATH}")
	target_link_libraries(${APPLICATION_NAME} application)

  add_custom_command(
    TARGET ${APPLICATION_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Qt5::Core> $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE:Qt5::Gui>
    $<TARGET_FILE_DIR:${APPLICATION_NAME}>
  )

  set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
  install(TARGETS ${APPLICATION_NAME} DESTINATION bin)
  install(
    FILES
      $<TARGET_FILE:Qt5::Core>
      $<TARGET_FILE:Qt5::Widgets>
      $<TARGET_FILE:Qt5::Gui>
    DESTINATION bin
  )

  get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
  get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
  find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")
  set(_install_dst "${CMAKE_INSTALL_PREFIX}/bin/${APPLICATION_NAME}.exe" )
  message("============================")
  message("execute_process( COMMAND \"${CMAKE_COMMAND}\" -E env PATH=\"${_qt_bin_dir}\" \"${WINDEPLOYQT_EXECUTABLE}\" --verbose 0 --no-compiler-runtime \"${_install_dst}\")")
  message("============================")
  install(CODE "execute_process( COMMAND \"${CMAKE_COMMAND}\" -E env PATH=\"${_qt_bin_dir}\" \"${WINDEPLOYQT_EXECUTABLE}\" --verbose 0 --no-compiler-runtime \"${_install_dst}\")")
endif()


