add_library(
  ui_menu_lib 
  menu_pane.cpp
)

target_include_directories(
  ui_menu_lib
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("menu_lib library compiled")

add_subdirectory(event_handlers)
