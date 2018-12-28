cmake_minimum_required(VERSION 3.6.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpendantic)
endif()

project(ChessProject)

include_directories(${DIRECTORY} logic)
set(SOURCE_FILES main.cpp logic/test.h logic/test.cpp )

add_executable(main ${SOURCE_FILES})

target_compile_features(main PRIVATE cxx_lambda_init_captures)
