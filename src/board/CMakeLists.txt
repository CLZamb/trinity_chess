add_library(
  board_lib
  board.cpp
  square.cpp
  squares.cpp
  board_fen.cpp
)

target_include_directories(board_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message("board_lib library compiled")

add_subdirectory(pieces)
add_subdirectory(special_moves)
