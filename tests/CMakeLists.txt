cmake_minimum_required(VERSION 3.6.2)

set(chess_tests ${CMAKE_PROJECT_NAME}_tests)
set(chess_lib ${CMAKE_PROJECT_NAME}_lib)

set(TESTS_SOURCE_FILES 
  gtest.cpp
)

# enable_testing()
add_executable(${chess_tests} ${TESTS_SOURCE_FILES})

target_link_libraries(${chess_tests} PUBLIC
  gtest_main
  gtest
  pthread
  # required libraries
  board_lib
  game_lib
  graphics_lib
  piece_lib
  player_lib
)

target_include_directories(
  ${chess_tests} PUBLIC
  "${PROJECT_SOURCE_DIR}/headers"
)

add_test(
  NAME ${chess_tests}
  COMMAND ${chess_tests}
)

include(GoogleTest)
gtest_discover_tests(${chess_tests})
