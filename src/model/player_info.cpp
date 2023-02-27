#include "headers/player_info.h"

PlayerInfo::PlayerInfo() {}
PlayerInfo::PlayerInfo(GameTurn::players gt) { this->m_gt = gt; }

void PlayerInfo::set_turn(const GameTurn::players &gt) { this->m_gt = gt; }
void PlayerInfo::set_color(const Color &c) { this->m_c = c; }
void PlayerInfo::set_type(const Type &t) { this->m_t = t; }

Color& PlayerInfo::get_color() { return m_c; }
PlayerInfo::Type& PlayerInfo::get_type() { return m_t; }
GameTurn::players& PlayerInfo::get_turn() { return m_gt; }
