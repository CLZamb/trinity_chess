cmake_minimum_required(VERSION 3.14.7)

set(chess_tests ${CMAKE_PROJECT_NAME}_tests)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(TESTS_SOURCE_FILES 
  g_test.cpp
  another_test.cpp
  pane_drawing_test.cpp
  board_window_test.cpp
)

add_executable(${chess_tests} ${TESTS_SOURCE_FILES})

include(add_google_test)
add_gtest(${chess_tests})

target_link_libraries(
  ${chess_tests} 
  PUBLIC
  game_lib
  board_lib
  position_lib
  board_check_lib
  board_check_pieces_lib
  board_special_moves_lib
  configuration_lib
  game_players_lib
  game_turn_lib
  #graphics
  board_window_lib
  ui_board_pane_lib
  ui_board_squares_lib
  ui_board_info_pane_lib
  ui_menu_lib
  ui_components_lib
  #input
  ui_input_keyboard_lib
  ui_input_text_lib
)

target_include_directories (
  ${chess_tests} 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
  "${PROJECT_SOURCE_DIR}/include"
)
