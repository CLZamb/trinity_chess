add_library(
  ui_board_event_handlers_lib
  board_keyboard_event_handler.cpp
  board_text_event_handler.cpp
)

target_include_directories(
  ui_board_event_handlers_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)
