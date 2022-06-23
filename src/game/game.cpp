#include "headers/game.h"

using std::cout;
using std::endl;

Game::Game(Configuration pc, PlayerInput& input) : 
  m_players_turn(pc.get_players_info()),
  m_board_info(m_board.get_info()),
  m_board_view(m_board.get_view()), 
  m_player_input(input) {
  setup_players();
  setup_board();
}

Game::~Game() {}

void Game::setup_players() {
  attach_observers_to_players_turn();
  m_players_turn.set_inital_side(GameTurn::player_1);
}

void Game::attach_observers_to_players_turn() { 
  m_players_turn.attach(&m_board);
  m_players_turn.attach(&m_board_info);
  m_players_turn.attach(&m_info_pane);
  m_players_turn.attach(&m_player_input);
}

void Game::setup_board() {
  m_board_view.add_pane_at_window_pos(&m_info_pane, Window::Right_pane);
}

void Game::play() {
  string str_move;
  m_player_input.setup(m_board_view);
  HumanPlayer hp;

  while (!m_board.is_checkmate()) {
    str_move = m_player_input.get_player_string_move(m_board_view, hp);

    if (!m_board.is_valid_move(str_move))
      continue;

    m_board.make_move(str_move);
    update_move_info_view();

    m_players_turn.change_turn();

    print_view();
  }

  if (!m_board.is_checkmate())  {
    cout << GameDrawing::game_over << endl;
    // winner_view.print();
  }
};
void Game::update_move_info_view() {
  m_info_pane.update_moves(m_board_info.get_moves());
  m_info_pane.update_captures(m_board_info.get_captures());
}

void Game::update_board_info_view() {
  m_info_pane.update_game_info(m_board_info.get_info());
}

void Game::print_view() {
  update_board_info_view();
  m_board_view.print();
}
