#ifndef BATTLESHIP__PLAYERCONFIGURATION_H_
#define BATTLESHIP__PLAYERCONFIGURATION_H_
namespace BattleShip {
class PlayerConfiguration {
 public:
  PlayerConfiguration();
  PlayerConfiguration(int numHumanPlayers, int numAiPlayers);
  int numHumanPlayers, numAiPlayers;
};
}
#endif
