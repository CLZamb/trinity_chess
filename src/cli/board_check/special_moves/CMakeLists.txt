add_library(
  special_moves_lib
  castling.cpp
  en_passant.cpp
  pawn_promotion.cpp
  special_move_controller.cpp
)

target_include_directories(
  special_moves_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  special_moves_lib 
  PUBLIC
  board_lib
)

message("special_moves_lib library compiled")
