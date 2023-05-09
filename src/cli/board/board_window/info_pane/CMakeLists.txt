add_library(
  ui_board_info_pane_lib
  board_check_info.cpp
  # model
  board_info_model.cpp
  # view
  info_view.cpp
  # controller
  info_pane.cpp
)

target_include_directories(
  ui_board_info_pane_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_board_info_lib library compiled")
