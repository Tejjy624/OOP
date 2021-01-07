#include <cctype>
#include "ExtraStringMethods.h"
#include "Contains.h"

const std::string whiteSpace(" \t\n");

std::string strip(const std::string& str, const std::string& trimCharacters) {
  std::string strippedString(str);
  stripInPlace(strippedString, trimCharacters);
  return strippedString;
}

void stripInPlace(std::string& str, const std::string& trimCharacters) {
  lstripInPlace(str, trimCharacters);
  rstripInPlace(str, trimCharacters);
}

std::string lstrip(const std::string& str, const std::string& trimCharacters) {
  std::string strippedString(str);
  lstripInPlace(strippedString, trimCharacters);
  return strippedString;
}

void lstripInPlace(std::string& str, const std::string& trimCharacters) {
  auto itr = str.begin();
  for (; itr != str.end(); ++itr) {
    if (!contains(trimCharacters, *itr)) {
      break;
    }
  }
  str.erase(str.begin(), itr);
}

std::string rstrip(const std::string& str, const std::string& trimCharacters) {
  std::string strippedString(str);
  rstripInPlace(strippedString, trimCharacters);
  return strippedString;
}

void rstripInPlace(std::string& str, const std::string& trimCharacters) {

  auto itr = str.rbegin();
  for (; itr != str.rend(); ++itr) {
    if (!contains(trimCharacters, *itr)) {
      break;
    }
  }
  /*
   * reverse_iterator.base gives you the forward iterator
   * but the reverse_iterator == reverse_iterator.base()-1
   */
  str.erase(itr.base(), str.rbegin().base());
}

std::string tolower(const std::string& str) {
  std::string lower(str);
  tolowerInPlace(lower);
  return lower;
}

void tolowerInPlace(std::string& str) {
  for (auto& letter : str) {
    letter = tolower(letter);
  }
}
