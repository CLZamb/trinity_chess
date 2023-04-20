add_library(
  ui_board_lib
  board_view.cpp
)

target_include_directories(
  ui_board_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_graphics_board_lib library compiled")

add_subdirectory(board_pane)
add_subdirectory(info_pane)
# add_subdirectory(statistics_pane)
