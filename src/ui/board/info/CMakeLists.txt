add_library(
  ui_board_info_lib
  # model
  board_model_info.cpp
  # view
  info_pane.cpp
  # controller
  board_info_controller.cpp
)

target_include_directories(ui_board_info_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message("ui_board_info_lib library compiled")
