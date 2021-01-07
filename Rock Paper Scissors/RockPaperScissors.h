#ifndef ROCKPAPERSCISSORS_ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_ROCKPAPERSCISSORS_H

#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include "ExtraRandomMethods.h"
#include "Contains.h"

//declarations
template<typename RandomNumberGeneratorType>
void replayableRockPaperScissors(RandomNumberGeneratorType& randomNumberGenerator);

template<typename RandomNumberGeneratorType>
void playRockPaperScissors(RandomNumberGeneratorType& randomNumberGenerator);

template<typename RandomNumberGeneratorType>
std::string getAiMove(RandomNumberGeneratorType& randomNumberGenerator);

std::string getPlayerMove();

void announcePlayResults(const std::string& playerMove, const std::string& aiMove);

std::string convertMoveToLongName(char shortMoveName);

std::string getPlayerInput(const std::string& prompt, const std::vector<std::string>& validInputs);

std::string getReplayChoice();

//definitions


template<typename RandomNumberGeneratorType>
void replayableRockPaperScissors(RandomNumberGeneratorType& randomNumberGenerator) {
  std::string replayChoice;
  do {
    playRockPaperScissors(randomNumberGenerator);
    replayChoice = getReplayChoice();
  } while (contains(replayChoice, 'y'));
}

template<typename RandomNumberGeneratorType>
void playRockPaperScissors(RandomNumberGeneratorType& randomNumberGenerator) {
  std::string playerMove, aiMove;
  do {
    aiMove = getAiMove(randomNumberGenerator);
    playerMove = getPlayerMove();

    std::cout << "The ai played " << aiMove << '.' << std::endl;
    announcePlayResults(playerMove, aiMove);
  } while (playerMove == aiMove);
}

template<typename RandomNumberGeneratorType>
std::string getAiMove(RandomNumberGeneratorType& randomNumberGenerator) {
  static const std::vector<std::string> moves{
      "rock", "paper", "scissors"};
  return *chooseRandom(moves, randomNumberGenerator);
}

#endif //ROCKPAPERSCISSORS_ROCKPAPERSCISSORS_H
