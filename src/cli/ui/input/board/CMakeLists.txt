add_library(
  ui_input_board_lib 
  INTERFACE
)

target_include_directories(
  ui_input_board_lib
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_subdirectory(keyboard)
add_subdirectory(text)
