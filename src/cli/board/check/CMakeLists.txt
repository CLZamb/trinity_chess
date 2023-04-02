add_library(
  board_check_lib
  board_check.cpp
)

target_include_directories(board_check_lib
  PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

message("ui_lib library compiled")

add_subdirectory(pieces)

target_link_libraries(
  board_check_lib
  PUBLIC
  board_lib
)
