#include "headers/players.h"

using std::make_unique;

Players::Players(const BoardFen &f, PlayersConfig &p, PlayerInput&i) : 
  m_fen(f) {
  create_players(p, i);
}

Players::~Players() {}

void Players::update_turn(const PlayerInfo & p) {
  m_turn = p;
}

void Players::create_players(PlayersConfig &c, PlayerInput& i) {
  create_player(GameTurn::player_1, c.get_type(GameTurn::player_1), i);
  create_player(GameTurn::player_2, c.get_type(GameTurn::player_2), i);
}

void Players::create_player(GameTurn::Players side, GameTurn::Type t, PlayerInput& i) {
  unordered_map<GameTurn::Players, SquareIndices> initial_pos = {
    {GameTurn::player_1, D3},
    {GameTurn::player_2, E6},
  };

  if (t == GameTurn::Human)
    m_players[side] = make_unique<HumanPlayer>(i, initial_pos[side]);
  else // t == CPU
    m_players[side] = make_unique<HumanPlayer>(i, initial_pos[side]);
}

string Players::get_next_string_move() {
  return m_players[m_turn.turn]->get_player_string_move();
}
