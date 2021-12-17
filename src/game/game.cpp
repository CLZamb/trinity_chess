#include "headers/game.h"

Game::Game(PlayerConfig pc) : 
  m_turn(GameTurn::player_1),
      initial_side(GameTurn::player_1 == m_turn ? "white" : "black") ,
      m_board_view(&m_board)
{
  attach(&m_board);
  setup_players(pc);
  setup_board();
}

Game::~Game() {}

void Game::start() {
  this->play();
}

void Game::setup_board() {
  m_board._init();
  m_board.update_game_info("Is player " + initial_side + " turn");
}

void Game::setup_players(PlayerConfig pc) {
  players.create_players(pc);
  game_turn = (GameTurn::player_1 == m_turn) ? players.get_player_1()
                                             : players.get_player_2();
}

void Game::play() {
  if (!game_players_exists()) {
    return;
  }

  string player_input = "";

  while (!m_board.is_checkmate()) {
    m_board_view.print();
    player_input = get_current_player_input();

    if (has_player_quit(player_input))
      break;
    if (!is_valid_str_move_format(player_input))
      continue;
    if (!is_legal_move(player_input))
      continue;

    make_move(player_input);
    change_turn();
  }
};

void Game::make_move(const string &move) {
  Move player_move = String::to_move(move);
  m_board.make_move(player_move);
}

bool Game::is_valid_str_move_format(const string &input) {
  if (String::is_valid_move_format(input))
    return true;

  m_board.update_game_info(
      "Move { " + input +
      " } - is an not in a recognizable format, please try again ");

  return false;
}

bool Game::is_legal_move(const string &str_player_move) {
  Move player_move = String::to_move(str_player_move);

  if (m_board.is_legal_move(game_turn, player_move))
    return true;

  m_board.update_game_info("Move { " + str_player_move +
                           " } is an ilegal move");

  return false;
}

bool Game::game_players_exists() {
  if (game_turn == nullptr) {
    cout << "players don't exists" << endl;
    return false;
  }
  return true;
}

bool Game::has_player_quit(const string &str) {
  return str == "quit" || str == "close" || str == "exit";
}

void Game::change_turn() {
  game_turn = game_turn->get_opponent();

  if (m_turn == GameTurn::player_2)
    m_turn = GameTurn::player_1;
  else // current_player == player_2
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
