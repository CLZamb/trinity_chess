add_library(
  game_turn_lib
  game_turn_observable.cpp
)

target_include_directories(
  game_turn_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  game_turn_lib 
  PUBLIC 
  utils_lib 
)
