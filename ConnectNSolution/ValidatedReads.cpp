#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "ValidatedReads.h"

bool ConnectNGame::onlyWhiteSpaceLeft(std::istream& in) {
  std::string input;
  in >> input;
  return !in;
}
