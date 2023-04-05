add_library(
  ui_input_board_keyboard_lib
  keyboard_input_board.cpp
)

target_include_directories(
  ui_input_board_keyboard_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("game library compiled")
