add_library(
  board_lib
  board.cpp
  board_with_info.cpp
  magic_bitboard.cpp
  move_validation.cpp
  info.cpp
  square.cpp
)

# add_executable(ipc ${SOURCE_FILES})

message("board library compiled")
