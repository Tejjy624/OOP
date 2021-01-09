#include "PlayerConfiguration.h"

BattleShip::PlayerConfiguration::PlayerConfiguration() = default;

BattleShip::PlayerConfiguration::PlayerConfiguration(int numHumanPlayers, int numAiPlayers) : numHumanPlayers(
    numHumanPlayers), numAiPlayers(numAiPlayers) {}
