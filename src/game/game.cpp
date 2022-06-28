#include "headers/game.h"
#include<chrono>

using std::cout;
using std::endl;

Game::Game(Configuration pc, PlayerInput& input) : 
  m_players_turn(pc.get_players_config()),
  m_board_info(m_board.get_info()),
  m_board_view(m_board.get_view()), 
  m_player_input(input),
  m_players(m_board.get_board_fen(), pc.get_players_config(), input)
{
  setup_players_turn();
  setup_board();
}

Game::~Game() {}

void Game::setup_players_turn() {
  attach_observers_to_players_turn();
  m_player_input.setup(m_board_view);
  m_players_turn.set_inital_side(GameTurn::player_1);
}

void Game::attach_observers_to_players_turn() { 
  m_players_turn.attach(&m_player_input);
  m_players_turn.attach(&m_board);
  m_players_turn.attach(&m_board_info);
  m_players_turn.attach(&m_info_pane);
  m_players_turn.attach(&m_players);
}

void Game::setup_board() {
  m_board_view.add_pane_at_window_pos(&m_info_pane, Window::Right_pane);
}

using namespace std::chrono; 	
void Game::play() {
  string str_move;

  while (!m_board.is_checkmate()) {
    print_view();

    str_move = m_players.get_next_string_move();

    if (!m_board.is_valid_move(str_move))
      continue;

    m_board.make_move(str_move);
    update_move_info_view();

    m_players_turn.change_turn();
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
