#ifndef BOARD_FEN_H
#define BOARD_FEN_H
#include "board/headers/square.h"
#include "board/headers/squares.h"
#include <string>

using std::string;

class BoardFen {
 public:
  BoardFen (Squares& s);
  virtual ~BoardFen ();
  void set_fen(const string &fen);
  const string &get_fen();

 private:
  void add_empty_space(string& fen, int &space);
  string fen;
  Squares &m_squares;
};

#endif /* BOARD_FEN_H */
