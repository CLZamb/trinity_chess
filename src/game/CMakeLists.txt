add_library(
  game_lib
  game.cpp
  game_turn_observable.cpp
)

target_include_directories(game_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message("game library compiled")

add_subdirectory(players)
