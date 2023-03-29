add_library(
  ui_input_text_lib
  text_base.cpp
  text_input.cpp
  text_input_player.cpp
)

message("ui_input_text_lib library compiled")
target_include_directories(ui_input_text_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
