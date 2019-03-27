#include "game.h"
Game::Game() {}
Game::~Game() { delete p_player2; }

void Game::start() {
  print_message("welcome");
  std::cin.get();
  print_message("start");
  int option = get_option();
  switch (option) {
  case 1:
  case 2:
    // create squares and set the pieces on those squares
    if (option == 1) {
      // Player vs Player
      p_player2 = new Player(BLACK);
    } else if (option == 2) {
      // Player vs CPU
      Movement::MoveGenerator AI_move_generator(&movement_controller);
      p_player2 = new AiPlayer(BLACK, &AI_move_generator);
    }
    m_board._init(&m_player1, p_player2);
    p_player2->set_opponent(&m_player1);
    m_player1.set_opponent(p_player2);
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

int Game::get_option() {
  std::cout << "\t\tchoose one of the options (1-4): ";
  int input;
  std::cin >> input;
  return input;
}

void Game::play() {
  bool is_checkMate = false;
  PlayerMove player_move;
  // clear input buffer
  std::cin.clear();
  std::cin.ignore();

  int counter = 0;
  while (!is_checkMate) {
    p_board_display->print();
    player_move = p_player_turn->get_next_move();

    if (player_move.m_input == "quit" ||
        player_move.m_input == "close" ||
        player_move.m_input == "exit")
      return;

    if (player_move.m_input == "undo") {
      movement_controller.undo_last_move();
      continue;
    }

    if (movement_controller.is_valid_move(player_move.m_move)) {
      movement_controller.move_piece(player_move.m_move);
      is_checkMate = movement_controller.get_checkmate();
      counter = 0;
    } else {
      // avoiding infinite loop
      if (counter == 4) break;
      std::cout << player_move.m_input << std::endl;
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
