add_library(drawings_lib INTERFACE)

target_include_directories(
  drawings_lib
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(
  drawings_lib 
  INTERFACE
  utils_lib
  ui_graphics_components_lib
)
