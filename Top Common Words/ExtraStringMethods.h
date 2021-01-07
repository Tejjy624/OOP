#ifndef TOPCOMMONWORDS_EXTRASTRINGMETHODS_H
#define TOPCOMMONWORDS_EXTRASTRINGMETHODS_H

#include <string>
#include <ostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> vector){
  if(!vector.empty()){
    auto itr = vector.cbegin();
    out << '{';
    for(; itr != vector.cend() - 1; ++itr){
      out << *itr << ", ";
    }
    out << *itr << '}';
  }
  return out;
}

//left and right strip
std::string strip(const std::string& str, const std::string& trimCharacters);
void stripInPlace(std::string& str, const std::string& trimCharacters);

//left strip
std::string lstrip(const std::string& str, const std::string& trimCharacters);
void lstripInPlace(std::string& str, const std::string& trimCharacters);


//right strip
std::string rstrip(const std::string& str, const std::string& trimCharacters);
void rstripInPlace(std::string& str, const std::string& trimCharacters);

//make string lower case
std::string tolower(const std::string& str);
void tolowerInPlace(std::string& str);



#endif //TOPCOMMONWORDS_EXTRASTRINGMETHODS_H
