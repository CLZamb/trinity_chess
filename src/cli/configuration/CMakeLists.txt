add_library(
  configuration_lib
  configuration.cpp
  file_configuration.cpp
  players_configuration.cpp
)

target_include_directories(
  configuration_lib 
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
  configuration_lib 
  PUBLIC
  ui_input_text_lib
)

message("configuration_lib library compiled")
