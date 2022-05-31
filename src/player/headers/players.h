#ifndef PLAYERS_H
#define PLAYERS_H

#include <memory>
#include <array>
#include "player.h"
#include "game/headers/game_turn_observable.h"
#include "configuration/headers/players_configuration.h"

using std::array;

class Players : public GameTurnObservable {
  public:
    Players(); 
    Players(PlayersConfig& config);
    virtual ~Players();
    void create_players(PlayersConfig& config);
    void notify();
    void change_turn();
    void set_inital_side(GameTurn::players p);
    std::shared_ptr<Player> get_player_turn();

  private:
    std::unique_ptr<Player> create_new_player(PlayerInfo& config);

    static const int players_size = GameTurn::kSize;
    array<PlayerInfo, players_size> players_info;
    array<std::shared_ptr<Player>, players_size> players;
    std::shared_ptr<Player> p_game_turn;
    PlayerInfo *m_turn;
};

#endif /* GAME_H */
