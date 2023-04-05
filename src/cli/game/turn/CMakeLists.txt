add_library(
  game_turn_lib
  game_turn_observable.cpp
)

target_include_directories(
  game_turn_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("game_turn_lib library compiled")
