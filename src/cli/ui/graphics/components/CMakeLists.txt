add_library(
 ui_graphics_components_lib
 Idisplay.cpp
 ISectionComponent.cpp
 pane.cpp
 section.cpp
 window.cpp
)

target_include_directories(
  ui_graphics_components_lib
  PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

message("ui_graphics_components_lib library compiled")
