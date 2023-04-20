add_library(
  ui_board_pieces_lib
  INTERFACE
)

target_include_directories(
  ui_board_pieces_lib
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
