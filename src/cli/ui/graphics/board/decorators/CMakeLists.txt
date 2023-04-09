add_library(
  ui_graphics_board_decorator_lib
  board_decorator.cpp
)

target_include_directories(
  ui_graphics_board_decorator_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

add_subdirectory(info)
