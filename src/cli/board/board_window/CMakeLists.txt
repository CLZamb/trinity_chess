add_library(
  ui_board_window_lib
  board_window.cpp
)

target_include_directories(
  ui_board_window_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_board_window_lib library compiled")

add_subdirectory(board_pane)
add_subdirectory(info_pane)
# add_subdirectory(statistics_pane)
