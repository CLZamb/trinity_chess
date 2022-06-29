#include "headers/game.h"

using std::make_unique;

Game::Game(Configuration pc, PlayerInput& input) : 
  m_players_turn(pc.get_players_config()),
  m_players(m_board.get_board_fen(), pc.get_players_config(), input),
  m_player_input(input),
  p_view_controller(std::make_unique<UiBoardController>(
    m_board_view, m_board.get_board_fen())) {
  setup_players_turn();
  add_info_to_board();
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

void Game::add_info_to_board() {
  m_board_view.add_pane_at_window_pos(&m_info_pane, Window::Right_pane);
  p_view_controller = std::make_shared<UiBoardInfoController>(p_view_controller, m_board_info, m_info_pane);
}

void Game::play() {
  string str_move;
  Move mv{0};
  p_view_controller->update();

  while (!m_board.is_checkmate()) {
    p_view_controller->print();

    str_move = m_players.get_next_string_move();
    mv = m_board.string_to_move(str_move);

    if (!is_valid_move(str_move, mv)) continue;

    make_move(mv);
    m_players_turn.change_turn();
  }

  if (!m_board.is_checkmate())  {
    std::cout << GameDrawing::game_over << std::endl;
    // winner_view.print();
  }
}

void Game::make_move(const Move& mv) {
  m_board.make_move(mv);
  m_board_info.save_move(mv);
  p_view_controller->update();
}

bool Game::is_valid_move(const string& str_move, Move& mv) {
  if (!string_utils::is_valid_move_format(str_move)) {
    m_board_info.wrong_format(str_move);
    return false;
  }

  if (!m_board.is_legal_move(mv)) {
    m_board_info.illegal_move(str_move);
    return false;
  }

  return true;
}
