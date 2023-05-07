add_library(
  ui_board_pane_lib
  board_pane.cpp
  keyboard_board_pane.cpp
  text_board_pane.cpp
)

target_include_directories(
  ui_board_pane_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_board_info_lib library compiled")

add_subdirectory(pieces)
add_subdirectory(squares)
