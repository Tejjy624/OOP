#ifndef VECTORGAME_VECTORGAME_H
#define VECTORGAME_VECTORGAME_H

#include <vector>
#include <ostream>

std::vector<int> solveVectorGame(const std::vector<int>& spaces);
void _solveVectorGame(const std::vector<int>& spaces,
                      std::vector<bool>& visitedSpace,
                      int curPosition,
                      std::vector<int>& curSolution,
                      std::vector<int>& optimalSolution);

template<typename T>
bool isValidIndex(int index, const std::vector<T>& vector) {
  return index >= 0 && index < static_cast<int>(vector.size());
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> vector) {
  out << '{';
  if (!vector.empty()) {
    auto end = vector.cend() - 1;
    for (auto itr = vector.begin(); itr != end; ++itr) {
      out << *itr << ", ";
    }
    out << vector.back();
  }
  out << '}';
  return out;
}

#endif //VECTORGAME_VECTORGAME_H
