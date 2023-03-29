#ifndef BOARD_MODEL_H
#define BOARD_MODEL_H

#include <string>

using std::string;

class BoardModel {
 public:
  BoardModel() = default;
  virtual ~BoardModel() = default;

  void set_fen(string& f) {
    this->_fen = std::move(f);
  }

  const std::string &get_fen() {
    return _fen;
  }

 private:
  std::string _fen;
};

#endif /* BOARD_VIEW_H */

