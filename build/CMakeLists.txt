# minimun required cmake version
cmake_minimum_required(VERSION 3.6.2)

# name of the project
project(ChessProject)

# minimum stardard library
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# flags
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
# chech if the the user is using  Visual Studio
if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(CHESS_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(CHESS_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CHESS_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(CHESS_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${CHESS_INSTALL_INCLUDE_DIR})
include_directories(${DIVISION_HEADERS_DIR})

add_subdirectory(include)
# add_subdirectory(libs)
add_subdirectory(src)
# add_subdirectory(tests)

# target_include_directories(Chess PUBLIC "${PROJECT_BINARY_DIR}")
