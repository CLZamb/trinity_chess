#include "configuration/configuration.h"

Configuration::Configuration() : m_players_config(GameTurn::Human, GameTurn::Human) {}

PlayersConfig& Configuration::get_players_config() { return m_players_config;}
