add_library(
  board_fen_lib
  board_fen.cpp
  board_fen_info.cpp
)

target_include_directories(
  board_fen_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  board_fen_lib
  PUBLIC
  utils_lib
  ui_board_lib
  special_moves_lib
)

message("board_fen_lib library compiled")
