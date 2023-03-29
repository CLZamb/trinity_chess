cmake_minimum_required(VERSION 3.14.7)

enable_testing()
set(chess_tests ${CMAKE_PROJECT_NAME}_tests)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(TESTS_SOURCE_FILES 
  g_test.cpp
  another_test.cpp
)

add_executable(${chess_tests} ${TESTS_SOURCE_FILES})

target_link_libraries(
  ${chess_tests} 
  PUBLIC
  board_lib
  piece_lib
  game_lib
  graphics_lib
  player_lib
)

include(add_google_test)
add_gtest(${chess_tests})
