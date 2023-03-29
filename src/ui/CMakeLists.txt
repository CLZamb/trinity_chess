add_library(
  ui_lib
  view.cpp
)

message("ui_lib library compiled")
target_include_directories(ui_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(board)
add_subdirectory(graphics)
add_subdirectory(menu)
add_subdirectory(input)
