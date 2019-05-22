#include "game.h"
Game::Game() {}
Game::~Game() {
  if (p_player1)
    delete p_player1;

  if (p_player2)
    delete p_player2;
}

void Game::start() {
  print_message(Welcome);
  std::cin.get();
  print_message(Start);

  switch (get_option(PLAYER_VS_PLAYER, CREDITS)) {
    case PLAYER_VS_PLAYER:
      set_players(HUMAN, HUMAN);
      play();
      break;
    case PLAYER_VS_CPU:
      set_players(HUMAN, CPU);
      play();
      break;
    case CPU_VS_CPU:
      set_players(CPU, CPU);
      play();
      break;
    case EXIT:
      print_message(GameOver);
      break;
    case CREDITS:
      std::cout << "Credits" << std::endl;
      break;
    default:
      std::cout << "Invalid Input:" << std::endl;
      break;
  }
}

void Game::set_players(Playertype p1, Playertype p2) {
  p_player1 =
    p1 == HUMAN ?
    new Player(WHITE) :
    new AiPlayer(WHITE, &movement_controller);

  p_player2 =
    p2 == HUMAN ?
    new Player(BLACK) :
    new AiPlayer(BLACK, &movement_controller);

  p_player_turn = p_player1;
  m_board.set_players(p_player1, p_player2);
  p_player2->set_opponent(p_player1);
  p_player1->set_opponent(p_player2);
}

int Game::get_option(int from, int to) {
  std::cout << "\t\tchoose one of the options ("<< from << "-" << to << "): ";
  int input;
  std::cin >> input;
  // clear input buffer
  std::cin.clear();
  std::cin.ignore();
  return input;
}

void Game::play() {
  m_board._init();
  movement_controller._init(p_player_turn->has_black_pieces());

  PlayerMove player_move;
  int counter = 0;
  bool is_checkMate = false;

  while (!is_checkMate) {
    // print board
    cout << m_board;
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

  std::cout << m_board << std::endl;
  if (is_checkMate) {
    std::cout << "checkmate\n";
    std::cout << "Player "
      << (p_player_turn->has_black_pieces()? "white" : "black")
      << " won.";
  }
}

void Game::print_message(Msg message) {
  system(CLEAR);
  Messages::m_nextMessage = message;
  p_message_display->print();
}

void Game::change_turn() { p_player_turn = p_player_turn->get_opponent(); }
