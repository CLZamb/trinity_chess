#ifndef PLAYERS_H
#define PLAYERS_H

#include <memory>
#include <unordered_map>
#include "configuration/players_configuration.h"
#include "game/turn/game_turn_observer.h"
#include "human_player.h"

using std::string;
// using std::array;
// using std::shared_ptr;

class Players : public GameTurnObserver {
public:
  // Players(PlayersConfig &, BoardInput&);
  virtual ~Players();
  // void update_turn(const PlayerInfo & p) override;
  // void create_players(PlayersConfig &c, BoardInput& i);
  // void create_player(GameTurn::Players p, GameTurn::Type t, BoardInput& i);
  // shared_ptr<Player> get_player(GameTurn::Players side);

private:
  // array<shared_ptr<Player>, Color::SIZE> m_players;
  PlayerInfo m_turn;
};

#endif /* PLAYERS_H */
