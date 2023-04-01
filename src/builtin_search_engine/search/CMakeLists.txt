add_library(
  search_lib
  search.cpp
)

message("search library compiled")
target_include_directories(search_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
