add_library(
  ui_board_squares_lib
  square_drawing.cpp
  square_drawings.cpp
  square_drawings_selector.cpp
)

target_include_directories(
  ui_board_squares_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)
