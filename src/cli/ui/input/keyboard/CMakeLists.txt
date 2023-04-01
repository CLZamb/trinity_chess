add_library(
  ui_input_keyboard_lib
  key_reader.cpp
  keyboard_base.cpp
  keyboard_input.cpp
  keyboard_input_player.cpp
)

target_include_directories(
  ui_input_keyboard_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  ui_input_keyboard_lib 
  PUBLIC 
  ui_input_lib
)

message("ui_input_keyboard_lib library compiled")
