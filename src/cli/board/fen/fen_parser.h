#ifndef BOARD_FEN_CONTROLLER_H
#define BOARD_FEN_CONTROLLER_H

#include "board/board_representation/position.hpp"
#include "game/turn/game_turn_observer.h"
#include "ui/board_window/board_pane/board_pane.h"
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class FenParser {
public:
  FenParser();
  virtual ~FenParser();
  void parse_fen(const string &fen, Position &p);
  string fen(Position &p);

private:
  char get_side_turn(const Color &c);
  string get_castling_rights_string(unsigned int castle_perm);
  string get_en_passant_square_string(const Square en_passant_sq);
  bool is_number(char c);
  void add_empty_space(string &fen, int &space);

  static const unordered_map<char, CastlePermission> m_castle_permision;
};

#endif /* BOARD_FEN_H */
