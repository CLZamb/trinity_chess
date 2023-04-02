set(chess ${CMAKE_PROJECT_NAME})

add_executable(${chess} main.cpp)

add_subdirectory(utils)
add_subdirectory(game)
add_subdirectory(ui)
add_subdirectory(board)
add_subdirectory(configuration)

target_link_libraries(
  ${chess} 
  PUBLIC
  game_lib
  ui_input_lib
  ui_menu_lib
  ui_input_keyboard_lib
  pieces_lib
  special_moves_lib
  board_lib
)

target_include_directories(
  ${chess} 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/include/common"
)
