add_library (
  input_lib
  INTERFACE
)

target_include_directories (
  input_lib
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_subdirectory(keyboard)
add_subdirectory(text)
