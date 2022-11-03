#ifndef BOARD_FEN_H
#define BOARD_FEN_H

#include "board/headers/board_fen_info.h"
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class BoardFen {
 public:
  BoardFen(BoardFenInfo& b, const string fen);
  virtual ~BoardFen();
  void parse_fen(const string &fen, BoardFenInfo& b);
  const string &get_fen();
  void update_fen(BoardFenInfo& b);
  void set_en_passant_pos(SquareIndices &sq);

 private:
  bool is_number(char c);
  void add_empty_space(string& fen, int &space);
  string m_board_fen;
  static const unordered_map<char, CastlePermission> m_castle_permision;
};

#endif /* BOARD_FEN_H */
