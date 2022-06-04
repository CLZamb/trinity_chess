#include "headers/game.h"

Game::Game(Configuration pc) : 
  m_players(pc.get_players_info(), pc.get_input_manager()),
  m_board_info(m_board.get_info()),
  m_board_view(m_board.get_view()){
  setup_players();
  setup_board();
}

Game::~Game() {}

void Game::setup_players() {
  attach_observers_to_players();
  m_players.set_inital_side(GameTurn::player_1);
  m_players.notify_change_turn();
}

void Game::attach_observers_to_players() {
  m_players.attach(&m_board);
  m_players.attach(&m_board_info);
  m_players.attach(&m_info_pane);
}

void Game::setup_board() {
  m_board_view.add_pane_at_window_pos(&m_info_pane, Window::Right_pane);
}

void Game::play() {
  string str_move;
  while (!m_board.is_checkmate()) {
    print_view();

    str_move = m_players.get_current_player_input();

    if (!m_board.is_valid_move(str_move))
      continue;

    m_board.make_move(str_move);
    m_players.change_turn();
  }
};

void Game::update_info_view() {
  m_info_pane.update_moves(m_board_info.get_moves());
  m_info_pane.update_captures(m_board_info.get_captures());
  m_info_pane.update_game_info(m_board_info.get_info());
}

void Game::print_view() {
  update_info_view();
  m_board_view.print();
}
