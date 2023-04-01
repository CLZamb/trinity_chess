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

message("${PROJECT_SOURCE_DIR}/src/utils")

target_include_directories(
  pieces_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}" 
)

target_link_libraries(
  pieces_lib 
  PUBLIC 
  board_lib
)

message("piece_lib library compiled")
