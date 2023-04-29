set(chess ${CMAKE_PROJECT_NAME})

add_executable(${chess} main.cpp)

add_subdirectory(board)
add_subdirectory(configuration)
add_subdirectory(game)
add_subdirectory(menu)
add_subdirectory(ui)
add_subdirectory(utils)

target_link_libraries (
  ${chess} 
  PRIVATE
  game_lib
  board_lib
  board_board_representation_lib
  board_check_lib
  board_check_pieces_lib
  board_special_moves_lib
  configuration_lib
  board_configuration
  game_players_lib
  game_turn_lib
  #graphics
  board_window_lib
  ui_board_pane_lib
  ui_board_squares_lib
  ui_board_info_pane_lib
  ui_board_event_handlers_lib
  ui_menu_lib
  ui_components_lib
  #input
  ui_input_keyboard_lib
  ui_input_text_lib
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
