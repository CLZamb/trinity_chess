add_library(
  ui_input_text_lib
  text_base.cpp
  text_input.cpp
  text_input_player.cpp
)

target_include_directories(
  ui_input_text_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  ui_input_text_lib 
  PUBLIC
  ui_input_lib
)

message("ui_input_text_lib library compiled")
