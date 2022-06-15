#ifndef PLAYERS_H
#define PLAYERS_H

#include <memory>
#include <array>
#include "game/headers/game_turn_observable.h"
#include "configuration/headers/players_configuration.h"
#include "input/headers/input.h"

using std::array;

class Players : public GameTurnObservable {
  public:
    Players(PlayersConfig& config);
    virtual ~Players();
    void create_players(PlayersConfig& config);
    void notify_change_turn();
    void change_turn();
    void set_inital_side(const GameTurn::Players &p);

  private:
    static const int players_size = GameTurn::kSize;
    array<PlayerInfo, players_size> players_info;
    GameTurn::Players m_turn;
};

#endif /* GAME_H */
