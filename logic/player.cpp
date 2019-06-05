#include "player.h"

Player::Player(bool has_black_pieces) : m_black_pieces(has_black_pieces) {}

Player::~Player() {}

PlayerMove Player::get_next_move() {
  std::string input;
  std::cout << "move piece ie: (a7 a6), to end the game type "
               "\"close, quite or exit\""
            << "\nis player " << (m_black_pieces? "black": "white") << " turn"
            << "\n>> ";
  std::getline(std::cin, input);
  set_next_move(input);
  return m_pl_move;
}

void Player::set_next_move(string input) {
  vector<string> list_pos;
  try {
    list_pos = scan(input, std::regex("([a-h][1-8])"));
  } catch (std::regex_error &e) {
    if (e.code() == std::regex_constants::error_badrepeat)
      std::cerr << "Repeat was not preceded by a valid regular expression.\n";
    else
      std::cerr << "Regex exception .\n";
  }

  if (list_pos.size() == 2) {
    int from = convert_to_int_pos(list_pos[0][0], list_pos[0][1]);
    int to = convert_to_int_pos(list_pos[1][0] , list_pos[1][1]);

    m_pl_move.set_valid(true);
    m_move.set_move(from, to);
  } else {
    m_pl_move.set_valid(false);
  }

  m_pl_move.set_move(m_move, input);
}

int Player::convert_to_int_pos(char file, char rank) {
  return (file - 'a') + ((rank - '1')*8);
}

vector<string> Player::scan(string str, const std::regex reg) {
  vector<string> results;
  std::smatch matches;
  while (std::regex_search(str, matches, reg)) {
    results.push_back(matches.str(1));
    str = matches.suffix().str();
  }
  return results;
}

void Player::set_opponent(Player* opponent) { this->p_opponent = opponent; }
bool Player::has_black_pieces() { return m_black_pieces; }
bool Player::is_valid_move() { return is_valid_input; }
Player* Player::get_opponent() { return p_opponent; }
void Player::save_played_moves(string mv) {
  played_moves = mv + " " + played_moves;
  if (played_moves.size() >= 250) {
    // remove the first 60 chars
    played_moves.resize(180);
  }
}
void Player::save_captured_pieces(string mv) {
  captured_pieces = mv + " " + captured_pieces;
  if (captured_pieces.size() >= 250) {
    // remove the first 60 chars
    captured_pieces.resize(180);
  }
}
string Player::get_played_moves() { return played_moves; }
string Player::get_captured_pieces() { return captured_pieces; }
