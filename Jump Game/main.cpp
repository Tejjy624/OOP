#include <iostream>
#include <string>
#include "VectorGame.h"

int main(int argc, char** argv) {

  std::vector<int> spaces;
  for (int i = 1; i < argc; ++i) {
    spaces.push_back(std::stoi(argv[i]));
  }
  auto solution = solveVectorGame(spaces);
  if (solution.empty()) {
    std::cout << "There is no solution to the given game." << std::endl;
  } else {
    std::cout << "The solution is: " << solution << std::endl;
  }
  return 0;
}
