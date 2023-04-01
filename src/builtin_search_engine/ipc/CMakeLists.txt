add_library(
  ipc_lib
  ipc_pipe.cpp
  cu_pipe.cpp
)

# add_executable(ipc ${SOURCE_FILES})
message("ipc library compiled")
target_include_directories(ipc_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
