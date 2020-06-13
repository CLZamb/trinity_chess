#include "headers/cli_display.h"

CliDisplay::CliDisplay(GuiController* gc) : p_gui_c(gc) {}
CliDisplay::~CliDisplay() {}

void CliDisplay::_init() {}

int CliDisplay::get_player_game_option_selection() {
  print_message(ChooseStartOption);
  return get_option(Begin_Options + 1, End_Options - 1);
}

int CliDisplay::get_option(int from, int to) {
  std::cout << "\t\tchoose one of the options ("<< from << "-" << to << "): ";
  int input;
  std::cin >> input;
  // clear input buffer
  std::cin.clear();
  std::cin.ignore();
  return input;
}

void CliDisplay::set_game_mode(int option) {
  switch (option) {
    case Player_vs_Player:
      set_board_players(HUMAN, HUMAN);
      break;
    case Player_vs_Cpu:
      set_board_players(HUMAN, CPU);
      break;
    case Cpu_vs_Cpu:
      set_board_players(CPU, CPU);
      break;
    default:
      break;
  }
}

void CliDisplay::print_message(Msg message) {
  static Messages m_message;
  Messages::m_nextMessage = message;
  system(CLEAR);
  m_message.print();
}

void CliDisplay::set_board_players(Playertype p1, Playertype p2) {
  std::cout << "player is: " << p1 << " player 2 is: " << p2 << std::endl;
}

typedef vector<string>::iterator vec_iter;
std::ostream& operator<<(std::ostream& os, CliDisplay& cli) {
  system(CLEAR);
  // left side of the screen
  // middle part of the screen
  // right side of the screen
  int dist = 0;
  for (vec_iter iter = cli.current_display.begin();
      iter != cli.current_display.end();
      iter++, dist++) {


    os << (*cli.p_gui_c->get_pane("board"))[dist]
      << (*cli.p_gui_c->get_pane("info"))[dist]
      << '\n';
  }

  return os;
}
