set(SOURCE_FILES
  main.cpp
  game.cpp
  player.cpp
  move_utils.cpp
  game_turn_observable.cpp
  )
# Exectuable
add_executable(Chess ${SOURCE_FILES})
# subdirectories
add_subdirectory(board)
add_subdirectory(graphics)
add_subdirectory(headers)
add_subdirectory(include)
add_subdirectory(ipc)
add_subdirectory(piece)
add_subdirectory(search)
# libraries links
target_link_libraries(Chess PUBLIC graphics_lib)
target_link_libraries(Chess PUBLIC common_lib)
target_link_libraries(Chess PUBLIC search_lib)
target_link_libraries(Chess PUBLIC ipc_lib)
target_link_libraries(Chess PUBLIC board_lib)
target_link_libraries(Chess PUBLIC piece_lib)
# includes headers
target_include_directories(
  Chess PUBLIC
  "${PROJECT_SOURCE_DIR}/graphics/headers"
  "${PROJECT_SOURCE_DIR}/ipc/headers"
  "${PROJECT_SOURCE_DIR}/search/headers"
  "${PROJECT_SOURCE_DIR}/board/headers"
  "${PROJECT_SOURCE_DIR}/piece/headers"
  "${PROJECT_SOURCE_DIR}/headers"
  "${PROJECT_SOURCE_DIR}/include"
  target_include_directories(search_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers/")
  "${PROJECT_SOURCE_DIR}/include/common/headers"
  )
