add_library(
  board_board_representation_lib
  board.cpp
  square.cpp
  squares.cpp
)

target_include_directories (
  board_board_representation_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("board_lib library compiled")
