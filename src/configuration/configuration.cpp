#include "headers/configuration.h"

Configuration::Configuration() : m_p_config(GameTurn::Human, GameTurn::Human) {}

PlayersConfig& Configuration::get_players_info() { return m_p_config;}
