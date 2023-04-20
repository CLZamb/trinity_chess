add_library(
  ui_board_info_pane_lib
  # model
  board_info_model.cpp
  # view
  info_pane.cpp
  # controller
  board_check_info_decorator.cpp
)

target_include_directories(
  ui_board_info_pane_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_board_info_lib library compiled")
