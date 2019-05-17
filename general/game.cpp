#include "game.h"
Game::Game() {}
Game::~Game() { delete p_player2; }

void Game::start() {
  print_message("welcome");
  std::cin.get();
  print_message("start");

  switch (get_option()) {
    case 1:
      // Player vs Player
      set_players();
      play();
    case 2:
      // Player vs CPU
      set_players(true);
      play();
      break;
    case 3:
      print_message("gameOver");
      break;
    case 4:
      std::cout << "Credits" << std::endl;
      break;
    default:
      std::cout << "Invalid Input:" << std::endl;
      break;
  }
}

void Game::set_players(bool is_cpu /*false*/) {
  if (is_cpu)
    p_player2 = new AiPlayer(BLACK, &movement_controller);
  else
    p_player2 = new Player(BLACK);

  m_board.set_players(&m_player1, p_player2);
  p_player2->set_opponent(&m_player1);
  m_player1.set_opponent(p_player2);
}

int Game::get_option() {
  std::cout << "\t\tchoose one of the options (1-4): ";
  int input;
  std::cin >> input;
  // clear input buffer
  std::cin.clear();
  std::cin.ignore();
  return input;
}

void Game::play() {
  m_board._init();

  PlayerMove player_move;
  int counter = 0;
  bool is_checkMate = false;

  while (!is_checkMate) {
    p_board_display->print();
    player_move = p_player_turn->get_next_move();

    if (player_move.get_input() == "quit" ||
        player_move.get_input() == "close" ||
        player_move.get_input() == "exit")
      return;

    if (player_move.get_input() == "undo") {
      movement_controller.undo_last_move();
      continue;
    }

    if (movement_controller.is_valid_move(player_move.get_move())) {
      movement_controller.move_piece(player_move.get_move());
      is_checkMate = movement_controller.get_checkmate();
      counter = 0;
    } else {
      // avoiding infinite loop
      if (counter == 4) break;
      std::cout << player_move.get_input() << std::endl;
      std::cout << "invalid move, try again\n";
      counter++;
    }
  }

  p_board_display->print();
  if (is_checkMate) {
    std::cout << "checkmate\n";
    std::cout << "Player "
      << (p_player_turn->has_black_pieces()? "white" : "black")
      << " won.";
  }
}

void Game::print_message(string message) {
  system(CLEAR);
  Messages::m_nextMessage = message;
  p_message_display->print();
}

void Game::change_turn() { p_player_turn = p_player_turn->get_opponent(); }
