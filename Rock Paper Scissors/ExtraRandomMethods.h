#ifndef ROCKPAPERSCISSORS_EXTRARANDOMMETHODS_H
#define ROCKPAPERSCISSORS_EXTRARANDOMMETHODS_H

#include <iterator>
#include <random>

//declarations
template<typename ContainerType, typename RandomGeneratorType>
typename ContainerType::const_iterator chooseRandom(const ContainerType& container, RandomGeneratorType& rand_gen);

//definitions

template<typename ContainerType, typename RandomGeneratorType>
typename ContainerType::const_iterator chooseRandom(const ContainerType& container, RandomGeneratorType& rand_gen) {
  int num_elements = std::distance(container.cbegin(), container.cend());
  std::uniform_int_distribution<> distribution(0, num_elements - 1);
  auto itr = container.cbegin();
  int move_amount = distribution(rand_gen);
  std::advance(itr, move_amount);
  return itr;
}

#endif //ROCKPAPERSCISSORS_EXTRARANDOMMETHODS_H
