#ifndef PLAYERS_H
#define PLAYERS_H

#include <memory>
#include "player.h"
#include "../../game/headers/game_turn_observable.h"

class Players {
  public:
    Players();
    virtual ~Players();
    void create_players(const PlayerConfig& config);
    std::shared_ptr<Player> get_player_1();
    std::shared_ptr<Player> get_player_2();

  private:
    std::unique_ptr<Player> create_new_player(Player::Type type, Color color);
    GameTurn::players m_turn = GameTurn::player_1;
    std::shared_ptr<Player> player_1, player_2, game_turn;
};

#endif /* GAME_H */
