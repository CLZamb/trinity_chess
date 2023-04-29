add_library(
  ui_board_squares_lib
  square_drawing.cpp
  squares_drawings.cpp
)

target_include_directories(
  ui_board_squares_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)
