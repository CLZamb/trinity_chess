add_library(
  ui_board_pane_lib
  board_pane.cpp
  board_pane_view.cpp

)

target_include_directories(
  ui_board_pane_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_board_info_lib library compiled")

add_subdirectory(pieces)
add_subdirectory(squares)
add_subdirectory(event_handlers)
