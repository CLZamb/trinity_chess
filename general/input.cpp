#include "input.h"

Input::Input() {}
Input::~Input() {}

void Input::getPlayerNextMove(std::string playerInput) {
  this->playerInput = playerInput;
  const std::regex r("(\\w\\w)");
  vector<std::string> positions = scan(playerInput, r);

  if (positions.size() == 2) {
    fromPos = positions[0];
    toPos = positions[1];
    validInput = true;
  } else {
    std::cout << "Wrong Input try again" << std::endl;
    validInput = false;
  }
}

vector<std::string> Input::scan(std::string str, std::regex reg) {
  vector<std::string> results;
  std::smatch matches;
  // std::cout << std::boolalpha;
  while (std::regex_search(str, matches, reg)) {
    results.push_back(matches.str(1));
    str = matches.suffix().str();
  }

  return results;
}

/*! \enum RowPosition
 *
 *  Detailed description
 */

Position Input::getPosFrom() {
  int x = fromPos[0] - 'a';
  int y = fromPos[1] - '1';
  return Position(x, y);
}

Position Input::getPosTo() {
  int x = toPos[0] - 'a';
  int y = toPos[1] - '1';
  return Position(x, y);
}

bool Input::equals(std::string other) { return !playerInput.compare(other); }

bool Input::isValidInput() { return validInput; }

ostream &operator<<(ostream &outputStream, const Input &p) {
  outputStream << p.fromPos;
  return outputStream;
}
