#ifndef BOARD_FEN_H
#define BOARD_FEN_H

#include <string>

using std::string;

class BoardFen {
 public:
  BoardFen() = default;
  virtual ~BoardFen() = default;

  void set_fen(string& f) {
    this->_fen = std::move(f);
  }

  const std::string &get_fen() const {
    return _fen;
  }

 private:
  std::string _fen;
};

#endif /* BOARD_VIEW_H */
