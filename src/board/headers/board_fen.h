#ifndef BOARD_FEN_H
#define BOARD_FEN_H
#include <string>

using std::string;

class BoardFen {
public:
  BoardFen ();
  virtual ~BoardFen ();
  void set_fen(const string &fen);
  const string &get_fen() const;

private:
  string fen;
};

#endif /* BOARD_FEN_H */
