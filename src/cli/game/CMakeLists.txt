add_library(
  game_lib
  game.cpp
)

target_include_directories(
  game_lib
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("game library compiled")

add_subdirectory(players)
add_subdirectory(turn)
