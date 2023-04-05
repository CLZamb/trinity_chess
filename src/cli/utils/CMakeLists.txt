add_library(
  utils_lib  
  INTERFACE
)

# sets the search paths for the include files after installation
# this allows users to #include the library headers
target_include_directories(
  utils_lib 
  INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

message("utils library compiled")
