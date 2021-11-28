#include "headers/game.h"
// #include <algorithm>

Game::Game():  
    m_turn(GameTurn::player_1),
    initial_side(GameTurn::player_1 == m_turn ? "white" : "black") 
{
  ui_controller.add_view(MessageView(&m_messages));
  attach(&m_board);
}

Game::~Game() {}

void Game::start() {
  if (get_play_or_quit_selection() == Options::Quit) {
    print_message(m_messages.get_game_over());
    return;
  }

  setup_players();
  setup_board();
  play();
}

void Game::setup_board() {
  m_board._init();
  m_board.update_game_info("Is player " + initial_side + " turn");
  ui_controller.add_view(BoardView(&m_board));
}

void Game::setup_players() {
  print_message(m_messages.get_players_options());
  players.create_players(get_players_selection());

  game_turn = (GameTurn::player_1 == m_turn)? players.get_player_1() : players.get_player_2();
}

int Game::get_play_or_quit_selection() {
  print_message(m_messages.get_start_or_quit());
  return options.get_selected_option({Options::Start, Options::Quit});
}

std::pair<Player::Type, Player::Type> Game::get_players_selection() {
  int opt = options.get_players_options();
  return options.get_players_selection(opt);
}

void Game::play() {
  string player_input = "";

  while (!m_board.is_checkmate()) {
    ui_controller.print_view(BoardView::Get_name());
    player_input = get_current_player_input();

    if (has_player_quit(player_input)) break;
    if (!is_valid_str_move_format(player_input)) continue;
    if (!is_legal_move(player_input)) continue;

    make_move(player_input);
    change_turn();
  }
};

void Game::make_move(const string& move) {
  Move player_move = MoveUtils::str_convert_to_move(move);
  m_board.make_move(player_move);
}

bool Game::is_valid_str_move_format(const string& input) {
  if (MoveUtils::is_valid_str_move_format(input))
    return true;

  m_board.update_game_info(
      "Move { " +
      input +
      " } - is an not in a recognizable format, please try again ");

  return false;
}

bool Game::is_legal_move(const string& str_player_move) {
  Move player_move = MoveUtils::str_convert_to_move(str_player_move);

  if(m_board.is_legal_move(game_turn, player_move))
    return true;

  m_board.update_game_info( "Move { " + str_player_move + " } is an ilegal move");

  return false;
}

bool Game::game_turn_exists() {
  if (game_turn == nullptr) {
    cout << "no players exists" << endl;
    return false;
  }
  return true;
}

bool Game::has_player_quit(const string& str) {
  return str == "quit" || str == "close" || str == "exit";
}

void Game::change_turn() {
  game_turn = game_turn->get_opponent();;

  if (m_turn == GameTurn::player_2)
    m_turn = GameTurn::player_1;
  else  // current_player == player_2
    m_turn = GameTurn::player_2;

  notify();
}

void Game::notify() {
  for (auto observer : *_observers) {
    observer->update_turn(m_turn);
  }
}

string Game::get_current_player_input() {
  string input;
  std::cout << std::endl << " >> ";
  std::getline(std::cin, input);
  std::cout << std::endl;
  return input;
}

void Game::print_message(MessageState* message) {
  m_messages.set_message(message);
  ui_controller.print_view(MessageView::Get_name());
}
