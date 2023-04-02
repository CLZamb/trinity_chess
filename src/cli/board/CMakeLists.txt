add_library(
  board_lib
  board.cpp
  square.cpp
  squares.cpp
)

target_include_directories(
  board_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  board_lib
  PUBLIC
  game_turn_lib
)

message("board_lib library compiled")

add_subdirectory(check)
add_subdirectory(fen)
add_subdirectory(special_moves)
