set(chess ${CMAKE_PROJECT_NAME})

add_executable(${chess} main.cpp)

add_subdirectory(board)
add_subdirectory(configuration)
add_subdirectory(game)
add_subdirectory(ui)
add_subdirectory(utils)

target_link_libraries (
  ${chess} 
  PRIVATE
  game_lib
  board_board_representation_lib
  board_check_lib
  board_check_pieces_lib
  board_fen_lib
  board_special_moves_lib
  configuration_lib
  game_players_lib
  game_turn_lib
  ui_graphics_board_lib
  ui_graphics_board_squares_lib
  ui_graphics_board_pane_lib
  ui_graphics_board_info_lib
  ui_graphics_components_lib
  ui_input_board_keyboard_lib
  ui_input_board_text_lib
  ui_input_inputtype_keyboard_lib
  ui_input_inputtypes_text_lib
  #INTERFACE
  # ui_graphics_board_pieces_lib
  # ui_graphics_drawings_lib
  # ui_menu_lib
  # ui_game_message_lib
  # ui_input_board_lib
  # ui_input_menu_keyboard_lib
  # ui_input_menu_text_lib
  # ui_input_menu_lib
  # utils_lib
)

target_include_directories(
  ${chess} 
  PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${PROJECT_SOURCE_DIR}/include"
)
