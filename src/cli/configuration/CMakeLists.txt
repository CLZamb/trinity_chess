add_library(
  configuration_lib
  # file_configuration.cpp
  default_configuration.cpp
  players_configuration.cpp
  board_configuration.cpp
)

target_include_directories(
  configuration_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("configuration_lib library compiled")
