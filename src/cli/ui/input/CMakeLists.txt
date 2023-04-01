add_library(
  ui_input_lib 
  INTERFACE
)

target_include_directories(
  ui_input_lib
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(
  ui_input_lib 
  INTERFACE
  ui_menu_lib
  players_lib
  board_lib
  ui_board_lib
)

add_subdirectory(keyboard)
add_subdirectory(text)
