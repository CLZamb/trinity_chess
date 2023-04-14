add_library(
 ui_graphics_components_lib
 ISectionComponent.cpp
 pane.cpp
 section.cpp
 window.cpp
)

target_include_directories(
  ui_graphics_components_lib
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("ui_graphics_components_lib library compiled")
