#include "game.h"

using std::make_shared;

Game::Game(Configuration& pc, PlayerInput& input) : 
      // m_ipc_search(),
      m_players_turn(pc.get_players_config()),
      m_board_check(m_board),
      m_board_fen(m_board, start_fen),
      m_board_controller(m_board_view,m_board_fen),
      m_players(pc.get_players_config(), input),
      m_player_input(input),
      p_boardview_controller(&m_board_controller) {
  m_player_input.setup(m_board_view);
  setup_players_turn();
  add_info_pane_to_board();
}

Game::~Game() {}

void Game::setup_players_turn() {
  attach_observers_to_players_turn();
  m_players_turn.set_inital_side(GameTurn::player_1);
}

void Game::attach_observers_to_players_turn() { 
  m_players_turn.attach(&m_player_input);
  m_players_turn.attach(&m_board);
  m_players_turn.attach(&m_board_model_info);
  m_players_turn.attach(&m_info_pane);
  m_players_turn.attach(&m_players);
  m_players_turn.attach(&m_board_check);
}

void Game::add_info_pane_to_board() {
  m_board_view.add_pane_at_window_pos(&m_info_pane, Window::Right_pane);
  p_boardview_controller = make_shared<UiBoardInfoController>(
      p_boardview_controller, m_info_pane, m_board_model_info);
}

void Game::play() {
  string str_move;
  string player_input;
  // m_ipc_search._init();
  Move mv;
  p_boardview_controller->update();
  // m_ipc_search._init();
  // m_ipc_search.request("position " + m_board_fen.get_fen());
  // player_input = m_ipc_search.request("go");
  std::cout << player_input  << std::endl;
  // player_input = string_utils::to_str_move(player_input);

  do {
    p_boardview_controller->print();

    str_move = m_players.get_next_string_move();
    mv = m_board.string_to_move(str_move);

    if (!is_valid_move(str_move, mv)) continue;

    make_move(mv);
    m_players_turn.change_turn();

  } while (!m_board_check.is_checkmate());

  if (m_board_check.is_checkmate())  {
    m_players_turn.change_turn();
    GameMessages::print_game_winner(m_players_turn.get_turn());
  } else {
    GameMessages::print_game_over();
  }
}

void Game::make_move(const Move& mv) {
  m_board.make_move(mv);
  m_board_fen.update_fen(m_board);
  update_board_view(mv);
}

void Game::update_board_view(const Move& mv) {
  m_board_model_info.save_move(mv);
  p_boardview_controller->update();
}

bool Game::is_valid_move(const string& str_move, Move& mv) {
  if (!string_utils::check::is_valid_move_format(str_move)) {
    m_board_model_info.wrong_format(str_move);
    return false;
  }

  if (m_board_check.is_in_check(mv) && !m_board_check.can_be_block_by_another_piece(mv)) {
    m_board_model_info.in_check(str_move);
    return false;
  }

  if (!m_board_check.is_legal_move(mv)) {
    m_board_model_info.illegal_move(str_move);
    return false;
  }

  return true;
}
