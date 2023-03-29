#ifndef BOARD_FEN_H
#define BOARD_FEN_H

#include <string>
#include <unordered_map>
#include "board_fen_info.h"
#include "ui/board/board_model.hpp"

using std::string;
using std::unordered_map;

class BoardFen : public BoardModel {
 public:
  BoardFen(BoardFenInfo& b, const string fen);
  virtual ~BoardFen();
  void parse_fen(const string &fen, BoardFenInfo& b);
  const string &get_fen();
  void update_fen(BoardFenInfo& b);

 private:
  bool is_number(char c);
  void add_empty_space(string& fen, int &space);
  static const unordered_map<char, CastlePermission> m_castle_permision;
};

#endif /* BOARD_FEN_H */
