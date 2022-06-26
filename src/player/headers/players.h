#ifndef PLAYERS_H
#define PLAYERS_H

#include <memory>
#include <string>
#include <unordered_map>
#include "board/headers/board_fen.h"
#include "configuration/headers/players_configuration.h"
#include "input/headers/input_type.h"
#include "player/headers/human_player.h"
#include "board/headers/board.h"

using std::string;
using std::array;
using std::unique_ptr;

class Players : public GameTurnObserver {
public:
  Players(const BoardFen &, PlayersConfig &, PlayerInput&);
  virtual ~Players();
  void update_turn(const PlayerInfo & p) override;
  void create_players(PlayersConfig &c, PlayerInput& i);
  void create_player(GameTurn::Players p, GameTurn::Type t, PlayerInput& i);
  string get_next_string_move();

private:
  const BoardFen& m_fen;
  array<unique_ptr<Player>, GameTurn::kSize> m_players;
  PlayerInfo m_turn;
};

#endif /* PLAYERS_H */
