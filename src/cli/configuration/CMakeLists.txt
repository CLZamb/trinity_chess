add_library(
  configuration_lib
  # file_configuration.cpp
  configuration.cpp
  players_configuration.cpp
)

target_include_directories(
  configuration_lib 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("configuration_lib library compiled")

add_subdirectory(board)
# add_subdirectory(game)
# add_subdirectory(file_configuration)


