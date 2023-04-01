add_library(
  game_lib
  game.cpp
)

target_include_directories(
  game_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  game_lib 
  PUBLIC
  ui_board_info_lib
  configuration_lib
)

message("game library compiled")

add_subdirectory(players)
add_subdirectory(turn)
