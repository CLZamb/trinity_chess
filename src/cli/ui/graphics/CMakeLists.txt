add_library(
  ui_graphics_drawings_lib 
  INTERFACE
)

target_include_directories(
  ui_graphics_drawings_lib 
  INTERFACE 
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(components)

message("ui_graphics_drawings_lib library compiled")
