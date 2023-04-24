#include "players.h"

// using std::unordered_map;
// using std::make_unique;

// Players::Players(PlayersConfig &p, BoardInput&i) {
  // create_players(p, i);
// }

Players::~Players() {}

// void Players::create_players(PlayersConfig &c, BoardInput& i) {
//   create_player(GameTurn::player_1, c.get_type(GameTurn::player_1), i);
//   create_player(GameTurn::player_2, c.get_type(GameTurn::player_2), i);
// }
//
// void Players::create_player(GameTurn::Players side, GameTurn::Type t, BoardInput& i) {
//   unordered_map<GameTurn::Players, Square> initial_pos = {
//     {GameTurn::player_1, D3},
//     {GameTurn::player_2, E6},
//   };
//
//   if (t == GameTurn::Human)
//     m_players[side] = make_unique<HumanPlayer>(i, initial_pos[side]);
//   else // t == CPU
//     m_players[side] = make_unique<HumanPlayer>(i, initial_pos[side]);
// }
//
// shared_ptr<Player> Players::get_player(GameTurn::Players side) {
//   return m_players[side];
// }
