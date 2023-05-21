add_library(
  board_check_pieces_lib
  piece.cpp
  pieces_legal_moves.cpp
  magic_bitboard.cpp
  piece.h
)

target_include_directories(
  board_check_pieces_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("piece_lib library compiled")
