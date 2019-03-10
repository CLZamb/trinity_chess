cmake_minimum_required(VERSION 3.6.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++11")

# chech if the the user is using  Visual Studio
if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

project(ChessProject)

include_directories(${DIRECTORY}
  logic
  display
  general
  general/pieces
  )

set(SOURCE_FILES
  main.cpp
  defs.h
  logic/board.h
  logic/board.cpp
  logic/player.h
  logic/player.cpp
  logic/AiPlayer.h
  logic/AiPlayer.cpp
  logic/movement.h
  logic/movement.cpp
  logic/move.h
  logic/bitboard.h
  logic/bitboard.cpp
  logic/transposition_table.h
  logic/transposition_table.cpp
  logic/Transposition_table_entry.h
  logic/Transposition_table_entry.cpp
  logic/ZobristKey.h
  logic/ZobristKey.cpp
  display/Idisplay.h
  display/Idisplay.cpp
  display/boxStruct.h
  general/game.h
  general/game.cpp
  general/messages.h
  general/messages.cpp
  general/pieces/piecesheaders.h
  general/pieces/bishop.h
  general/pieces/bishop.cpp
  general/pieces/king.h
  general/pieces/king.cpp
  general/pieces/knight.h
  general/pieces/knight.cpp
  general/pieces/pawn.h
  general/pieces/pawn.cpp
  general/pieces/piece.h
  general/pieces/piece.cpp
  general/pieces/queen.h
  general/pieces/queen.cpp
  general/pieces/rook.h
  general/pieces/rook.cpp
  )

set(
  CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_HOME_DIRECTORY}/bin
  )

add_executable(main ${SOURCE_FILES})
target_compile_features(main PRIVATE cxx_lambda_init_captures)
