#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Box2D" for configuration "Debug"
set_property(TARGET Box2D APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Box2D PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libBox2D.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS Box2D )
list(APPEND _IMPORT_CHECK_FILES_FOR_Box2D "${_IMPORT_PREFIX}/lib/libBox2D.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
