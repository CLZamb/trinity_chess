add_library(
  input_text_lib
  text_input_base.cpp
  text_input.cpp
)

target_include_directories(
  input_text_lib 
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("input_text_lib library compiled")
