add_library(
  ui_graphics_board_lib
  board_view.cpp
)

target_include_directories(
  ui_graphics_board_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_graphics_board_lib library compiled")

add_subdirectory(panes)
add_subdirectory(pieces)
add_subdirectory(squares)
