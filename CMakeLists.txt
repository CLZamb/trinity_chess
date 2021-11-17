# minimun required cmake version
cmake_minimum_required(VERSION 3.6.2)

# name of the project
project(
  Chess
  VERSION 2.0
  DESCRIPTION "Terminal based chess game"
  LANGUAGES CXX
  )
#
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

#For the Curses library to load:
# SET(CURSES_USE_NCURSES TRUE)
add_subdirectory(src)
add_subdirectory(tests)

# googl tests
target_include_directories(
  Chess PUBLIC 
  "${PROJECT_SOURCE_DIR}/src"
  "${PROJECT_BINARY_DIR}/bin"
  )

# target_compile_features(Chess PRIVATE cxx_std_17)
# adding lambda feature
# target_compile_features(Chess PRIVATE cxx_lambda_init_captures)
# set_property(Chess TARGET PROPERTY CXX_STANDARD 17)

