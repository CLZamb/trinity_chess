#include "headers/configuration.h"

Configuration::Configuration() : m_p_config(PlayerInfo::Human, PlayerInfo::Human) {}

PlayersConfig& Configuration::get_players_info() { return m_p_config;}

