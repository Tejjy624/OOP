#ifndef CONNECTN_VALIDATEDREADS_H
#define CONNECTN_VALIDATEDREADS_H

#include <string>
#include <sstream>
#include <iostream>

namespace ConnectNGame {
  template<typename T>
  T getValidInput(std::istream& in, std::ostream& out, const std::string& prompt);

  bool onlyWhiteSpaceLeft(std::istream& in);

  template<typename T>
  T getValidInput(std::istream& in, std::ostream& out, const std::string& prompt) {
    T desiredInput;
    std::string line;
    bool inputIsValid = static_cast<bool>(in);

    do {
      out << prompt;
      std::getline(in, line);
      std::stringstream input(line);
      input >> desiredInput;

      //input is valid if we read the value successfully
      //and there is only whitespace afterwards
      inputIsValid = input && onlyWhiteSpaceLeft(input);

    } while (!inputIsValid);

    return desiredInput;
  }

}

#endif //CONNECTN_VALIDATEDREADS_H
