cmake_minimum_required(VERSION 3.6.2)

set(CMAKE_CXX_STANDARD 11)

# chech if the the user is using  Visual Studio
if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

project(ChessProject)

include_directories(${DIRECTORY}
  src/display
  src/general
  src/general/pieces
  src/logic
  src/logic/search
  )

set(SOURCE_FILES
  src/main.cpp
  src/display/Idisplay.h
  src/display/Idisplay.cpp
  src/display/boxStruct.h
  src/display/drawings.hpp
  src/display/drawings.cpp
  src/logic/board.h
  src/logic/board.cpp
  src/logic/player.h
  src/logic/player.cpp
  src/logic/AiPlayer.h
  src/logic/AiPlayer.cpp
  src/logic/magic_bitboard.h
  src/logic/magic_bitboard.cpp
  src/logic/movement.h
  src/logic/movement.cpp
  src/logic/move.h
  src/logic/bitboard.h
  src/logic/bitboard.cpp
  src/logic/search/Search.h
  src/logic/search/Search.cpp
  src/logic/search/transposition_table.h
  src/logic/search/transposition_table.cpp
  src/logic/search/Transposition_table_entry.h
  src/logic/search/Transposition_table_entry.cpp
  src/logic/search/ZobristKey.h
  src/logic/search/ZobristKey.cpp
  src/general/defs.h
  src/general/game.h
  src/general/game.cpp
  src/general/messages.h
  src/general/messages.cpp
  src/general/pieces/piece.h
  src/general/pieces/piece.cpp
  src/general/utils.h
  )

set(
  CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_HOME_DIRECTORY}/bin
  )

add_executable(main ${SOURCE_FILES})
target_compile_features(main PRIVATE cxx_lambda_init_captures)
