add_library(
  board_check_lib
  chess_validator.cpp
)

target_include_directories(
  board_check_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("board_check_lib library compiled")

add_subdirectory(pieces)
