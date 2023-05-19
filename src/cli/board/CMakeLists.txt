add_library(
  board_lib
  board.cpp
  chess.cpp
)

target_include_directories(
  board_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
  "${PROJECT_SOURCE_DIR}/include"
)

add_subdirectory(board_window)
add_subdirectory(check_move)
add_subdirectory(position)
add_subdirectory(special_moves)
