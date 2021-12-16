cmake_minimum_required(VERSION 3.14.7)

set(chess_tests ${CMAKE_PROJECT_NAME}_tests)

set(TESTS_SOURCE_FILES 
  gtest.cpp
)

add_executable(${chess_tests} ${TESTS_SOURCE_FILES})

target_link_libraries(${chess_tests} PUBLIC
  gtest
  gmock
  gtest_main
  pthread
  # required libraries
  board_lib
  game_lib
  graphics_lib
  piece_lib
  player_lib
)

include(GoogleTest)
# gtest
message(STATUS ${gtest_SOURCE_DIR})
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


target_include_directories(
  ${chess_tests} PUBLIC
  "${PROJECT_SOURCE_DIR}/headers"
)

add_test(
  NAME ${chess_tests}
  COMMAND ${chess_tests}
)

gtest_discover_tests(${chess_tests})
