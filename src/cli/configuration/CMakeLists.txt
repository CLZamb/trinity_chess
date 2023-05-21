add_library(
  configuration_lib
  configuration.cpp
  players_configuration.cpp
)

target_include_directories(
  configuration_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
  "${PROJECT_SOURCE_DIR}/include"
)

message("configuration_lib library compiled")
