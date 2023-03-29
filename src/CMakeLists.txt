set(chess ${CMAKE_PROJECT_NAME})

add_executable(${chess} main.cpp)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(board)
add_subdirectory(configuration)
add_subdirectory(game)
# add_subdirectory(ipc)
# add_subdirectory(search)
add_subdirectory(ui)
add_subdirectory(utils)

target_link_libraries(
  ${chess} PUBLIC
  game_lib
  ui_lib
  ui_board_info_lib
  ui_board_lib
  ui_input_keyboard_lib
  ui_input_text_lib
  ui_graphics_components_lib
  board_lib
  configuration_lib
  # ipc_lib)
  pieces_lib
  special_moves_lib
  players_lib
  # search_lib
)

target_include_directories(
  ${chess} 
  PRIVATE 
  "${PROJECT_SOURCE_DIR}/include/common"
)
