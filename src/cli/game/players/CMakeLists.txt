add_library(
  game_players_lib
  ai_player.cpp
  human_player.cpp
)

target_include_directories(
  game_players_lib
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("players_lib library compiled")
