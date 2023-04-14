add_library(
  ui_graphics_board_lib
  square_drawing.cpp
  squares_drawings.cpp
  board_ui.cpp
  board_view.cpp
  board_pane.cpp
)

target_include_directories(
  ui_graphics_board_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_graphics_board_lib library compiled")

add_subdirectory(decorators)
add_subdirectory(pieces)
