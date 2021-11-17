#include "headers/game.h"
#include <algorithm>

Game::Game() : m_board(),  
  m_turn(GameTurn::player_1),
  initial_side(GameTurn::player_1 == m_turn ? "white" : "black") {
  m_messages_window.add_pane(&m_messages, Window::Left_pane);
  attach(&m_board);
}

Game::~Game() {}

void Game::start() {
  if (get_start_or_quit_selection() == Quit) {
    print_message(m_messages.get_game_over());
    return;
  } // else start

  play();
}

int Game::get_start_or_quit_selection() {
  print_message(m_messages.get_start_or_quit());
  return get_selected_option({Start, Quit});
}

void Game::_init() {
  setup_players();
  m_board._init();
  m_board.update_game_info("Is player " + initial_side + " turn");

  m_game_window.add_pane(m_board.get_board_drawing(), Window::Middle_pane);
  m_game_window.add_pane(m_board.get_info_drawing(), Window::Right_pane);
}

void Game::setup_players() {
  create_players(get_players_selection());

  game_turn = (GameTurn::player_1 == m_turn)? player_1 : player_2;
  player_1->set_opponent(player_2);
  player_2->set_opponent(player_1);
}

void Game::play() {
  _init();

  if (!game_turn_exists())
    return;

  Move player_move;
  string player_input = "";

  while (!m_board.is_checkmate()) {
    cout << m_game_window;
    player_input = get_current_player_input();

    if (has_player_quit(player_input)) break;
    if (!MoveUtils::is_valid_str_move_format(player_input)) {
      m_board.update_game_info(
          "Move { " +
          player_input +
          " } - is an not in a recognizable format, please try again ");
      continue;
    }

    player_move = MoveUtils::str_convert_to_move(player_input);

    if (!m_board.is_legal_move(game_turn, player_move)) {
      m_board.update_game_info(
          "Move { " +
          player_input +
          " } is an ilegal move");
      continue;
    }

    m_board.make_move(player_move);
    change_turn();
  }
};

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

pair<Player::Type, Player::Type> Game::get_players_selection() {
  print_message(m_messages.get_players_options());

  int opt =
    get_selected_option(m_players_selections.get_configurations_options());

  return m_players_selections.get_pair_players_type(
      static_cast<PlayersSelections::Players_configuration>(opt));
}

int Game::get_selected_option(vector<int> opts) {
  std::cout << "\t\tchoose one of the options ("
    << opts.front() << "-"
    << opts.back() << "): ";

  int input = -1;
  bool valid_option = false;

  while (!valid_option) {
    std::cin >> input;
    valid_option = check_valid_option(input, opts);

    if (!valid_option) {
      cout << "invalid option try again!" << endl;
      std::cin.clear();
      std::cin.ignore();
    }
  }

  std::cin.clear();
  std::cin.ignore();
  return input;
}

bool Game::check_valid_option(int i, const vector<int>& opts) {
  return std::find(opts.begin(), opts.end(), i) != opts.end();
}

void Game::
create_players(const std::pair<Player::Type, Player::Type>& p_type) {
  player_1 = create_new_player(p_type.first, WHITE);
  player_2 = create_new_player(p_type.second, BLACK);
}

std::unique_ptr<Player>
Game::create_new_player(Player::Type type, Color color) {
  if (type == Player::Human)
    return std::make_unique<Player>(Player(color));
  // else Playyer::CPU
  return std::make_unique<Player>(Player(color));
}

void Game::print_message(MessageState* message) {
  m_messages.set_message(message);
  cout << m_messages_window << endl;
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

