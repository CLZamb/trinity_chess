add_library(
  position_lib
  position.cpp
  board_representation.cpp
  castling_rights.cpp
  half_move_clock.cpp
  position_fen.cpp
)

target_include_directories (
  position_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("board_lib library compiled")
