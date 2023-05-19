add_library(
  ui_board_pane_event_handlers_lib
  keyboard_event_handler.cpp
  text_event_handler.cpp
)

target_include_directories(
  ui_board_pane_event_handlers_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("board_pane_event_handlers_lib library compiled")
