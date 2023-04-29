add_library(
  board_window_lib
  board_window.cpp
)

target_include_directories(
  board_window_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_graphics_board_lib library compiled")

add_subdirectory(board_pane)
add_subdirectory(event_handlers)
add_subdirectory(info_pane)
# add_subdirectory(statistics_pane)
