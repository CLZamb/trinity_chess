add_library(
  input_keyboard_lib
  key_reader.cpp
  keyboard.cpp
  keyboard_input.cpp
)

target_include_directories(
  input_keyboard_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_input_keyboard_lib library compiled")
