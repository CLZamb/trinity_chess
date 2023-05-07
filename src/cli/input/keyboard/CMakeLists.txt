add_library(
  ui_input_keyboard_lib
  key_reader.cpp
  keyboard.cpp
  keyboard_input.cpp
)

target_include_directories(
  ui_input_keyboard_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_input_keyboard_lib library compiled")
