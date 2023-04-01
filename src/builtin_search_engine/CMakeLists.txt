set(SOURCE_FILES
  main.cpp
  uci.cpp
)

add_executable(search ${SOURCE_FILES})

add_subdirectory(ipc)
add_subdirectory(search)

target_link_libraries(
  search PUBLIC
  ipc_lib
  search_lib
)
