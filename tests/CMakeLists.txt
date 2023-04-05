cmake_minimum_required(VERSION 3.14.7)

set(chess_tests ${CMAKE_PROJECT_NAME}_tests)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(TESTS_SOURCE_FILES 
  g_test.cpp
  another_test.cpp
)

add_executable(${chess_tests} ${TESTS_SOURCE_FILES})

include(add_google_test)
add_gtest(${chess_tests})

target_link_libraries(
  ${chess_tests} PUBLIC
  board_representation_lib
  board_check_pieces_lib
  special_moves_lib
)

