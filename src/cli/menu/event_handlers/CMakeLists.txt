add_library(
  ui_menu_event_handlers_lib 
  INTERFACE
)

target_include_directories(
  ui_menu_event_handlers_lib 
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
