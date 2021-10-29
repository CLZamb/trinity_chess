
add_library(
  piece_lib
  bishop.cpp
  king.cpp
  knight.cpp
  pawn.cpp
  piece.cpp
  pieces_drawings.cpp
  queen.cpp
  rook.cpp
)

# add_executable(ipc ${SOURCE_FILES})

message("piece library compiled")
