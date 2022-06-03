#include "headers/configuration.h"

Configuration::Configuration(Input& i) : m_p_config(PlayerInfo::Human, PlayerInfo::Human) , m_input(i) {}

PlayersConfig& Configuration::get_players_info() { return m_p_config;}
Input& Configuration::get_input_manager() { return m_input;}
