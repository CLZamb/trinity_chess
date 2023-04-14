add_library(
  board_check_lib
  board_check.cpp
  board_check_behaviour.cpp
)

target_include_directories(
  board_check_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("board_check_lib library compiled")

add_subdirectory(pieces)
