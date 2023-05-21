add_library(
  chess_lib
  chess.cpp
)

target_include_directories(
  chess_lib
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
  "${PROJECT_SOURCE_DIR}/include"
)

message("game library compiled")

add_subdirectory(check_move)
add_subdirectory(position)
add_subdirectory(special_moves)
