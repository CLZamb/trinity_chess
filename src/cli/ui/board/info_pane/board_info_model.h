#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include "game/turn/game_turn_observer.h"
#include "savable.h"
#include "utils/string_utils.h"

using std::string;
using StringDrawingName::Pieces::pawn;
using StringDrawingName::Pieces::rook;
using StringDrawingName::Pieces::knight;
using StringDrawingName::Pieces::bishop;
using StringDrawingName::Pieces::queen;
using StringDrawingName::Pieces::king;

class BoardModelInfo : public Savable, public GameTurnObserver {
public:
  BoardModelInfo();
  virtual ~BoardModelInfo();

  void update_info_turn(const PlayerInfo& e);
  void update_turn(const PlayerInfo &p) override;
  void save_move(const Move &move) override;
  void save_info(const string &info) override;

  string get_moves(Color c) override;
  string get_captures(Color c) override;
  string get_info() override;
  PlayerInfo get_player_info() override;

private:
  string get_piece_str_name_from_piecetype(Piecetype piece_type) {
    const unordered_map<Piecetype, string> piece_str_name{
      {bP, pawn},   {bR, rook},   {bN, knight}, {bB, bishop},
      {bQ, queen},  {bK, king},   {wP, pawn},   {wR, rook},
      {wN, knight}, {wB, bishop}, {wQ, queen},  {wK, king}
    };

    auto search = piece_str_name.find(piece_type);
    // check if the key exists
    if (search == piece_str_name.end())
      return "";

    return search->second;
  }
  string get_move_string(const Move &m);
  string get_captured_string(const Move &m);
  PlayerInfo m_player_info;
};

#endif /* BOARD_INFO_H */
