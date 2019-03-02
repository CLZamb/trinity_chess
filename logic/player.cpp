#include "player.h"

Player::Player(std::string c) : m_colorPieces(c) {}
Player::~Player() {}

Move Player::getPlayerNextMove() {
  std::string input;
  std::cout << "move piece ie: (a7 a6), to end the game type "
               "\"close, quite or exit\""
            << "\nis player " << this->m_colorPieces << " turn"
            << "\n>> ";
  std::getline(std::cin, input);
  setNextMove(input);
  return m_Move;
}

void Player::setNextMove(string playerInput) {
  vector<string> positions;
  try {
    positions = scan(playerInput, std::regex("([a-h][1-8])"));
  } catch (std::regex_error &e) {
    if (e.code() == std::regex_constants::error_badrepeat)
      std::cerr << "Repeat was not preceded by a valid regular expression.\n";
    else
      std::cerr << "Regex exception .\n";
  }

  if (positions.size() == 2) {
    int fromFile = positions[0][0] - 'a';
    int fromRank = (positions[0][1] - '1') * 8;
    int toFile = positions[1][0] - 'a';
    int toRank = (positions[1][1] - '1') * 8;
    int from = fromFile + fromRank;
    int to = toFile + toRank;

    m_Move.m_validMove = true;
    m_Move.setValidMove(true);
    m_Move.setMove(from, to, 0);
  } else {
    m_Move.m_validMove = false;
    m_Move.setValidMove(false);
  }

  m_Move.m_input = playerInput;
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
