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

target_include_directories(
  ui_board_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  ui_board_lib 
  PUBLIC
  ui_lib
  ui_board_pieces_lib
  drawings_lib
)

message("ui_board_lib library compiled")

add_subdirectory(info)
add_subdirectory(pieces)

