#include "headers/game.h"

Game::Game() : m_board_with_info(&m_board, &m_info) {
  m_messages_gui.add_pane_at_pos(&m_messages, GuiController::Left_pane);
  attach(&m_board);
  attach(&m_info);
  attach(&m_board_with_info);
}

Game::~Game() {}

void Game::start() {
  if (get_start_or_quit_selection() == Quit) {
    print_message(m_messages.get_game_over());
    return;
  }

  print_message(m_messages.get_players_options());
  Players_Selection selection = get_players_selection();

  set_players_on_board(players_selections[selection]);
  play();
}

int Game::get_start_or_quit_selection() {
  print_message(m_messages.get_start_or_quit());
  return get_option(Start, Quit);;
}

void Game::_init() {
  m_info._init();
  m_board._init();

  m_main_gui.add_pane_at_pos(&m_board, GuiController::Middle_pane);
  m_main_gui.add_pane_at_pos(&m_info, GuiController::Right_pane);

  m_ipc_search._init();
  m_info.save_game_info(
      "Is player " +
      m_board.get_turn()->get_str_color_pieces() +
      " turn");

  cout << m_main_gui;
}

void Game::play() {
  _init();

  string player_input = "";
  while (!m_board.is_checkmate()) {
    current_player = m_board.get_turn();
    current_player->get_input(player_input);

    if (has_player_quit(player_input))
      break;

    if (!MoveUtils::is_valid_str_move_format(player_input)) {
      m_info.save_game_info(
          "Move { " +
          player_input +
          " } - is an not in a recognizable format, please try again ");
      cout << m_main_gui;
      continue;
    }

    player_move = MoveUtils::str_convert_to_move(player_input);
    m_board_with_info.make_move(player_move);
    change_turn();
    // m_board_with_info.change_turn();

    cout << m_main_gui;
  }
}

bool Game::has_player_quit(const string& str) {
  return str == "quit" || str == "close" || str == "exit";
}

Game::Players_Selection Game::get_players_selection() {
  return static_cast<Players_Selection>(
      get_option(Players_selections_begin + 1, Players_selections_end - 1));
}

int Game::get_option(int from, int to) {
  std::cout << "\t\tchoose one of the options ("<< from << "-" << to << "): ";
  int input;
  std::cin >> input;
  std::cin.clear();
  std::cin.ignore();
  return input;
}

void Game::
set_players_on_board(const std::pair<Player::Type, Player::Type>& p_type) {
  player_1 = create_new_player(p_type.first, Player::white);
  player_2 = create_new_player(p_type.second, Player::black);
  m_board.set_players(player_1, player_2);
}

std::unique_ptr<Player> Game::
create_new_player(Player::Type type, Player::Color color) {
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

  if (current_player == player_1)
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
