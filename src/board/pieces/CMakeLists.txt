add_library(
  pieces_lib
  rook.cpp
  bishop.cpp
  king.cpp
  knight.cpp
  pawn.cpp
  queen.cpp
  piece.cpp
  pieces.cpp
  magic_bitboard.cpp
)

target_include_directories(pieces_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message("piece_lib library compiled")
