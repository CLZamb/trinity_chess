#include "headers/game.h"

Game::Game()
    : m_turn(GameTurn::player_1),
      initial_side(GameTurn::player_1 == m_turn ? "white" : "black") {
  ui_controller.add_view(MessageView(&m_messages));
  attach(&m_board);
  setup_players();
  setup_board();
}

Game::~Game() {}

void Game::start() {
  this->play();
}

string Game::select_option(const string &play, const string &quit) {
  Options<string> options{play, quit};

  print_message(m_messages.get_play_or_quit());
  return options.select_option();
}

void Game::setup_board() {
  m_board._init();
  m_board.update_game_info("Is player " + initial_side + " turn");
  ui_controller.add_view(BoardView(&m_board));
}

void Game::setup_players() {
  Options<PlayerConfig> player_options{
      {Player::Human, Player::Human},
      {Player::Human, Player::Cpu},
      {Player::Cpu, Player::Cpu},
  };

  print_message(m_messages.get_players_options());
  players.create_players(player_options.select_option());

  game_turn = (GameTurn::player_1 == m_turn) ? players.get_player_1()
                                             : players.get_player_2();
}

void Game::play() {
  if (!game_players_exists()) {
    return;
  }

  string player_input = "";

  while (!m_board.is_checkmate()) {
    ui_controller.print_view(BoardView::Get_name());
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

void Game::print_message(MessageState *message) {
  m_messages.set_message(message);
  ui_controller.print_view(MessageView::Get_name());
}
