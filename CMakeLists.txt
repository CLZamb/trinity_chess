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

add_subdirectory(src)
#
target_include_directories(
  Chess PUBLIC 
  "${PROJECT_BINARY_DIR}/bin"
  "${PROJECT_SOURCE_DIR}/src"
  )

# target_compile_features(Chess PRIVATE cxx_std_17)
# adding lambda feature
# target_compile_features(Chess PRIVATE cxx_lambda_init_captures)
# set_property(Chess TARGET PROPERTY CXX_STANDARD 17)

