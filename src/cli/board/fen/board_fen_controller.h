#ifndef BOARD_FEN_CONTROLLER_H
#define BOARD_FEN_CONTROLLER_H

#include <string>
#include <unordered_map>
#include "board/board_representation/board.h"
#include "board/fen/board_fen_model.h"
#include "game/turn/game_turn_observer.h"

using std::string;
using std::unordered_map;

class BoardFenController : public GameTurnObserver {
 public:
  BoardFenController(Board& b, const string fen);
  virtual ~BoardFenController();
  void update_turn(const PlayerInfo &) override;
  void parse_fen(const string &fen);
  void update_fen();

 private:
  bool is_number(char c);
  void add_empty_space(string& fen, int &space);

  BoardFenModel m_board_fen_info;
  static const unordered_map<char, CastlePermission> m_castle_permision;
};

#endif /* BOARD_FEN_H */
