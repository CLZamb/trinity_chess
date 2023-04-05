add_library(
  ui_graphics_drawings_lib 
  INTERFACE
)

target_include_directories(
  ui_graphics_drawings_lib
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  "${PROJECT_SOURCE_DIR}/src/cli"
)

message("graphis_drawings library compiled")
