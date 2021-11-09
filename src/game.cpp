#include "headers/game.h"
#include <algorithm>

Game::Game() : m_board_with_info() {
  m_messages_gui.add_pane_at_pos(&m_messages, GuiController::Left_pane);
  attach(&m_board_with_info);
  initial_side = (GameTurn::player_1 == m_turn) ? "white" : "black" ;
}

Game::~Game() {}

void Game::start() {
  if (get_start_or_quit_selection() == Quit) {
    print_message(m_messages.get_game_over());
    return;
  }

  set_players_on_board(get_players_selection());
  play();
}

int Game::get_start_or_quit_selection() {
  print_message(m_messages.get_start_or_quit());
  return get_selected_option({Start, Quit});
}

void Game::_init() {
  m_board_with_info._init();
  // if (player_1 == Player::Cpu || player_2 == Player::Cpu)
  //   m_ipc_search._init();

  Displayable* board = m_board_with_info.get_board_drawing();
  Displayable* info = m_board_with_info.get_info_drawing();

  m_main_gui.add_pane_at_pos(board, GuiController::Middle_pane);
  m_main_gui.add_pane_at_pos(info, GuiController::Right_pane);

  m_board_with_info.update_turn(m_turn);
  m_board_with_info.update_game_info(
      "Is player " + initial_side + " turn");
  cout << m_main_gui;
}

void Game::play() {
  _init();

  string player_input = "";

  while (!m_board_with_info.is_checkmate()) {
    current_player = m_board_with_info.get_turn();
    current_player->get_input(player_input);

    if (has_player_quit(player_input))
      break;

    if (!MoveUtils::is_valid_str_move_format(player_input)) {
      m_board_with_info.update_game_info(
          "Move { " +
          player_input +
          " } - is an not in a recognizable format, please try again ");
      cout << m_main_gui;
      continue;
    }

    player_move = MoveUtils::str_convert_to_move(player_input);

    if (!m_board_with_info.is_legal_move(player_move)) {
      m_board_with_info.update_game_info(
          "Move { " +
          player_input +
          " } is an ilegal move");
      cout << m_main_gui;
      continue;
    }

    m_board_with_info.make_move(player_move);
    change_turn();

    cout << m_main_gui;
  }
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
set_players_on_board(const std::pair<Player::Type, Player::Type>& p_type) {
  player_1 = create_new_player(p_type.first, WHITE);
  player_2 = create_new_player(p_type.second, BLACK);
  m_board_with_info.set_players(player_1, player_2);
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
  cout << m_messages_gui << endl;
}

void Game::change_turn() {
  current_player = current_player->get_opponent();;

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
