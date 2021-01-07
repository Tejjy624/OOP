#include <iterator>
#include <algorithm>
#include <stdexcept>
#include "RockPaperScissors.h"
#include "ExtraStringMethods.h"
#include "Contains.h"

std::string getPlayerMove() {
  static const std::string shortNames("rps");
  static const std::vector<std::string> validMoves{
      "rock", "(r)ock", "r",
      "paper", "(p)aper", "p",
      "scissors", "(s)cissors", "s"
  };

  static const std::string prompt("Enter (R)ock, (P)aper, or (S)cissors for your move: ");

  std::string playerMove = getPlayerInput(prompt, validMoves);

  auto move = std::find_first_of(playerMove.cbegin(), playerMove.cend(), shortNames.cbegin(), shortNames.cend());

  return convertMoveToLongName(*move);
}

void announcePlayResults(const std::string& playerMove, const std::string& aiMove) {
  //each element beats the next in the list
  static const std::vector<std::string> winningTriangle{
      "rock", "scissors", "paper"};

  //find the index in the above vector each player made their move at
  auto playerItr = std::find(winningTriangle.cbegin(), winningTriangle.cend(), playerMove);
  auto aiItr = std::find(winningTriangle.cbegin(), winningTriangle.cend(), aiMove);
  auto playerIndex = std::distance(winningTriangle.cbegin(), playerItr);
  auto aiIndex = std::distance(winningTriangle.cbegin(), aiItr);

  if (playerMove == aiMove) {
    std::cout << "You and the AI both played " << playerMove << '.' << std::endl;
    std::cout << "Keep playing until someone wins." << std::endl;
  } else if (static_cast<unsigned int>(aiIndex) == (playerIndex + 1) % winningTriangle.size()) {
    //the ai played a move after the one the user made in winningTriangle
    //the the user will win
    std::cout << "You win!" << std::endl;
  } else {
    std::cout << "The AI wins :(" << std::endl;
  }
}

std::string convertMoveToLongName(char shortMoveName) {
  static const std::vector<std::string> longNames{
      "rock", "paper", "scissors"
  };

  for (const auto& longName : longNames) {
    if (contains(longName, shortMoveName)) {
      return longName;
    }
  }

  throw std::invalid_argument("Short Name must be one of r, p, or s");

}

std::string getPlayerInput(const std::string& prompt, const std::vector<std::string>& validInputs) {
  std::string playerInput;
  do {
    std::cout << prompt;
    std::getline(std::cin, playerInput);
    stripInPlace(playerInput);
    tolowerInPlace(playerInput);
  } while (!contains(validInputs, playerInput));
  return playerInput;
}

std::string getReplayChoice() {
  static const std::vector<std::string> validMoveChoices{
      "yes", "y", "(y)es",
      "no", "n", "(n)o"
  };
  static const std::string prompt("Would you like to replay the game?\n"
                                  "Enter (Y)es or (N)o: ");
  return getPlayerInput(prompt, validMoveChoices);
}

