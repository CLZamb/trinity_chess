add_library(
  players_lib
  ai_player.cpp
  players_turn_controller.cpp
  human_player.cpp
  players.cpp
)

target_include_directories(
  players_lib
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  players_lib
  PUBLIC
  configuration_lib 
)

message("players_lib library compiled")
