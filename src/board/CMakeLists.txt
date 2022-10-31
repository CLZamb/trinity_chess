add_library(
  board_lib
  board.cpp
  square.cpp
  squares.cpp
  board_fen.cpp
  castling.cpp
  en_passant.cpp
  pawn_promotion.cpp
  special_move_controller.cpp
)

message("board library compiled")
