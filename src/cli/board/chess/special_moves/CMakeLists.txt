add_library(
  board_special_moves_lib
  castling.cpp
  en_passant.cpp
  pawn_promotion.cpp
  special_move_controller.cpp
)

target_include_directories(
  board_special_moves_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("special_moves_lib library compiled")
