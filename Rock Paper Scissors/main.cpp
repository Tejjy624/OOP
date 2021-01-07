#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include "RockPaperScissors.h"

int main(int argc, char** argv) {
  std::minstd_rand randomNumberGenerator;
  if (argc >= 2) {
    randomNumberGenerator.seed(std::stoi(argv[1]));
  } else {
    randomNumberGenerator.seed(time(nullptr));
  }

  replayableRockPaperScissors(randomNumberGenerator);

  return 0;
}
