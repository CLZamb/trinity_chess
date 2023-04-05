add_library(
  ui_input_board_text_lib
  text_input_board.cpp
)

target_include_directories(
  ui_input_board_text_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)
