add_subdirectory(info)

add_library(
  ui_board_lib
  board_decorator.cpp
  square_drawing.cpp
  # view
  board_view.cpp
  # model
  # controller
  board_controller.cpp
)

target_include_directories(ui_board_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message("ui_board_lib library compiled")
