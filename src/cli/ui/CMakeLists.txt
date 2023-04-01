add_library(
  ui_lib
  view.cpp
)

target_include_directories(ui_lib
  PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

message("ui_lib library compiled")

add_subdirectory(graphics)
add_subdirectory(drawings)
add_subdirectory(board)
add_subdirectory(input)
add_subdirectory(menu)
