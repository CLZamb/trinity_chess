# minimun required cmake version
cmake_minimum_required(VERSION 3.6.2)

# name of the project
project(ChessProject)

if(WIN32)
  message("WIN32")
endif(WIN32)

add_library(
  src
  main.cpp
  game.cpp
  player.cpp
  )

# setting the output directory
set(
  CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_HOME_DIRECTORY}/../bin
  )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# subdirectories
add_subdirectory(display)
add_subdirectory(search)
add_subdirectory(ipc)
add_subdirectory(headers)
add_subdirectory(board)

set(SOURCE_FILES
  main.cpp
  game.cpp
  player.cpp
  )

add_executable(main ${SOURCE_FILES})
target_compile_features(main PRIVATE cxx_lambda_init_captures)
# libraries links
target_link_libraries(main PUBLIC display_lib)
target_link_libraries(main PUBLIC common_lib)
target_link_libraries(main PUBLIC search_lib)
target_link_libraries(main PUBLIC ipc_lib)
target_link_libraries(main PUBLIC board_lib)

target_compile_features(display_lib PUBLIC cxx_constexpr)
# includes headers
target_include_directories(
  main PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/display/headers"
  "${PROJECT_SOURCE_DIR}/ipc/headers"
  "${PROJECT_SOURCE_DIR}/search/headers"
  "${PROJECT_SOURCE_DIR}/board/headers"
  "${PROJECT_SOURCE_DIR}/headers"
  target_include_directories(search_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers/")
  "${PROJECT_SOURCE_DIR}/include/common/headers"
  )
