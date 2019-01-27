#include "input.h"

Input::Input() {}
Input::~Input() {}

void Input::getNextMove(std::string playerInput) {
  this->playerInput = playerInput;

  vector<std::string> positions = scan(playerInput, std::regex("(\\w\\w)"));

  if (positions.size() == 2) {
    std::string from = positions[0], to = positions[1];
    fromPos.setPosition(from[0], from[1]);
    toPos.setPosition(to[0], to[1]);
    validInput = true;
  } else {
    std::cout << "Wrong Input try again" << std::endl;
    validInput = false;
  }
}

vector<std::string> Input::scan(std::string str, const std::regex reg) {
  vector<std::string> results;
  std::smatch matches;
  // std::cout << std::boolalpha;
  while (std::regex_search(str, matches, reg)) {
    results.push_back(matches.str(1));
    str = matches.suffix().str();
  }

  return results;
}

Position Input::getPosFrom() { return fromPos; }
Position Input::getPosTo() { return toPos; }
bool Input::isValidInput() { return validInput; }
std::string Input::toString() { return this->playerInput; }
