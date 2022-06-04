#ifndef PLAYERS_H
#define PLAYERS_H

#include <memory>
#include <array>
#include "player.h"
#include "game/headers/game_turn_observable.h"
#include "configuration/headers/players_configuration.h"
#include "player/headers/input.h"

using std::array;

class Players : public GameTurnObservable {
  public:
    Players(PlayersConfig& config, Input& input);
    virtual ~Players();
    void create_players(PlayersConfig& config);
    void notify_change_turn();
    void change_turn();
    void set_inital_side(GameTurn::players p);
    std::shared_ptr<Player> get_player_turn();
    const string& get_current_player_input();

  private:
    static const int players_size = GameTurn::kSize;
    array<PlayerInfo, players_size> players_info;
    std::shared_ptr<Player> p_game_turn;
    PlayerInfo *m_turn;
    Input& m_input;
};

#endif /* GAME_H */
