#ifndef TOPCOMMONWORDS_CONTAINS_H
#define TOPCOMMONWORDS_CONTAINS_H

#include <algorithm>

template<typename ContainerType, typename ValueType>
bool contains(const ContainerType& container, const ValueType& value) {
  return std::find(container.begin(), container.end(), value) != container.end();
}

#endif //TOPCOMMONWORDS_CONTAINS_H
