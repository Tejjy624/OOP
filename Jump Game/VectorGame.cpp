#include "VectorGame.h"

void _solveVectorGame(const std::vector<int>& spaces,
                      int curPosition,
                      std::vector<int>& curSolution,
                      std::vector<int>& solutions);

std::vector<int> solveVectorGame(const std::vector<int>& spaces) {
  if (spaces.empty()) {
    return {};
  } else {
    std::vector<int> optimalSolution;
    std::vector<int> curSolution;
    std::vector<bool> visitedSpace(spaces.size(), false);
    curSolution.reserve(spaces.size()); //small optimization to preallocate space
    _solveVectorGame(spaces, visitedSpace, 0, curSolution, optimalSolution);

    return optimalSolution;
  }
}

void _solveVectorGame(const std::vector<int>& spaces,
                      std::vector<bool>& visitedSpace,
                      int curPosition,
                      std::vector<int>& curSolution,
                      std::vector<int>& optimalSolution) {

  if (visitedSpace.at(curPosition)) {
    return; //been here before so no point in coming back
  }

  //visit this space
  curSolution.push_back(curPosition);
  visitedSpace.at(curPosition) = true;

  //reached the end so we must have solved the puzzle
  if (curPosition == spaces.size() - 1) {
    //update the best answer if
    //it is either the first time we solved the problem
    //or the current solution is better than the old one
    if (optimalSolution.empty() || curSolution.size() < optimalSolution.size()) {
      optimalSolution = curSolution;
    }
  } else {
    const std::vector<int> adjacentSpaces{
        curPosition - spaces.at(curPosition),
        curPosition + spaces.at(curPosition)
    };
    for (const auto& adjacentSpace : adjacentSpaces) {
      if (isValidIndex(adjacentSpace, spaces)) {
        _solveVectorGame(spaces, visitedSpace, adjacentSpace, curSolution, optimalSolution);
      }
    }

  }

  //leave this space
  curSolution.pop_back();
  visitedSpace.at(curPosition) = false;

}
