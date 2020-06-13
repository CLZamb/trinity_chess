add_library(
  search_lib
  uci.cpp
  search.cpp
  )

set(SOURCE_FILES
  main.cpp
  uci.cpp
  search.cpp
  )

add_executable(search ${SOURCE_FILES})

message("search library compiled")
