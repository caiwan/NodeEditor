# includes the platform specific layer only to bootstrap the application
if (WIN32)
    add_subdirectory(windows)
endif()

if( APPLE )    
    add_subdirectory(mac)
endif()

if (UNIX AND NOT APPLE)
    add_subdirectory(linux)
endif()
