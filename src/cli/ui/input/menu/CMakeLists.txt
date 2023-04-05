add_library(
  ui_input_menu_lib 
  INTERFACE
)

target_include_directories(
  ui_input_menu_lib
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

message("ui_input_menu_lib library compiled")

add_subdirectory(keyboard)
add_subdirectory(text)
