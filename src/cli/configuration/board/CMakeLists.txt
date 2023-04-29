add_library(
  board_configuration
  board_configuration.cpp
)

target_include_directories(
  board_configuration 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("board_configuration libray compiled")
