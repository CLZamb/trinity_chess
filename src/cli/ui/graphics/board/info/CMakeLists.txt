add_library(
  ui_graphics_board_info_lib
  # model
  board_model_info.cpp
  # view
  info_pane.cpp
  # controller
  board_info_controller.cpp
)

target_include_directories(
  ui_graphics_board_info_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_board_info_lib library compiled")
