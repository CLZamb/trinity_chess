add_library(
  board_lib
  board.cpp
  square.cpp
  squares.cpp
  board_fen.cpp
  castling.cpp
  special_move.cpp
  en_passant.cpp
)

message("board library compiled")
