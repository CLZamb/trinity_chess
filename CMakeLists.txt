cmake_minimum_required(VERSION 3.14.7)

set(chess Chess)

project(
  Chess
  VERSION 2.0
  DESCRIPTION "Terminal based chess game"
  LANGUAGES CXX C
  )

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

#flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# install(
#     TARGETS foo
#     LIBRARY DESTINATION lib
#     ARCHIVE DESTINATION lib
#     RUNTIME DESTINATION bin
# )

set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard to conform to")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# compile command for lsp-server clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include(GNUInstallDirs)
######################
# public headers     # 
######################
add_subdirectory(include)
######################
# source files       # 
######################
add_subdirectory(src)
######################
# Unit testing       # 
######################
enable_testing()
add_subdirectory(tests)
