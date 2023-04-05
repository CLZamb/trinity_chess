add_library(
  ui_input_menu_text_lib 
  INTERFACE
)

target_include_directories(
  ui_input_menu_text_lib
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
