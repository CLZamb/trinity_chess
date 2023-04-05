add_library(
  ui_graphics_board_pieces_lib
  INTERFACE
)

target_include_directories(
  ui_graphics_board_pieces_lib
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

  # "${CMAKE_CURRENT_SOURCE_DIR}"
  # "${CMAKE_CURRENT_SOURCE_DIR}/board"
  # "${CMAKE_CURRENT_SOURCE_DIR}/utils"
  # "${CMAKE_CURRENT_SOURCE_DIR}/src/cli/board/board_representation"
  # PUBLIC 
  # "${CMAKE_CURRENT_SOURCE_DIR}"
# target_include_directories(
#   ui_board_pieces_lib 
#   INTERFACE 
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#   $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
# )
