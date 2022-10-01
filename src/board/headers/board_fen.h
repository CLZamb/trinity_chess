#ifndef BOARD_FEN_H
#define BOARD_FEN_H

#include "board/headers/squares.h"
#include <string>

using std::string;

class BoardFen {
 public:
  BoardFen (Squares& s);
  virtual ~BoardFen();
  void parse_fen(const string &fen, BoardBitboard& b_b);
  const string &get_fen();
  void update_fen();

 private:
  bool is_number(char c);
  void add_empty_space(string& fen, int &space);
  Squares &m_squares;
  string m_board_fen;
};

#endif /* BOARD_FEN_H */
