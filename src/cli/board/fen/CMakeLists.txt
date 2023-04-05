add_library(
  board_fen_lib
  board_fen.cpp
  board_fen_info.cpp
)

target_include_directories(
  board_fen_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("board_fen_lib library compiled")
