cmake_minimum_required(VERSION 2.8.11)

# Mac only stuff 
if( APPLE )    
    add_executable(${APPLICATION_NAME} MACOSX_BUNDLE "main.cpp")

    # Add system frameworks
    ADD_SYSTEM_FRAMEWORK( Foundation ${APPLICATION_NAME} )
    ADD_SYSTEM_FRAMEWORK( CoreFoundation ${APPLICATION_NAME} )
    ADD_SYSTEM_FRAMEWORK( AppKit ${APPLICATION_NAME})

    # Identify MacOS bundle
    set(MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME})
    set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})
    set(MACOSX_BUNDLE_LONG_VERSION_STRING ${PROJECT_VERSION})
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")
    set(MACOSX_BUNDLE_COPYRIGHT ${COPYRIGHT})
    set(MACOSX_BUNDLE_GUI_IDENTIFIER ${IDENTIFIER})
    set(MACOSX_BUNDLE_ICON_FILE ${ICON_NAME})

    include_directories("${APPLICATION_SOURCE_PATH}")

# Add the Qt5 Widgets for linking
	target_link_libraries(${APPLICATION_NAME} application)

endif()
