#ifndef ROCKPAPERSCISSORS_EXTRASTRINGMETHODS_H
#define ROCKPAPERSCISSORS_EXTRASTRINGMETHODS_H

#include <string>

extern const std::string whiteSpace;

//left and right strip
std::string strip(const std::string& str, const std::string& trimCharacters = whiteSpace);
void stripInPlace(std::string& str, const std::string& trimCharacters = whiteSpace);

//left strip
std::string lstrip(const std::string& str, const std::string& trimCharacters = whiteSpace);
void lstripInPlace(std::string& str, const std::string& trimCharacters = whiteSpace);

//right strip
std::string rstrip(const std::string& str, const std::string& trimCharacters = whiteSpace);
void rstripInPlace(std::string& str, const std::string& trimCharacters = whiteSpace);

std::string tolower(const std::string& str);
void tolowerInPlace(std::string& str);

#endif //ROCKPAPERSCISSORS_EXTRASTRINGMETHODS_H
