#ifndef PLAYERS_H
#define PLAYERS_H

#include "configuration/players_configuration.h"
#include "ui/input/input_type.h"
#include "human_player.h"
#include "board/board.h"

using std::string;
using std::array;
using std::unique_ptr;

class Players : public GameTurnObserver {
public:
  Players(PlayersConfig &, PlayerInput&);
  virtual ~Players();
  void update_turn(const PlayerInfo & p) override;
  void create_players(PlayersConfig &c, PlayerInput& i);
  void create_player(GameTurn::Players p, GameTurn::Type t, PlayerInput& i);
  string get_next_string_move();

private:
  array<unique_ptr<Player>, GameTurn::kSize> m_players;
  PlayerInfo m_turn;
};

#endif /* PLAYERS_H */
