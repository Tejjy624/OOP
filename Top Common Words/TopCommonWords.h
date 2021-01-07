#ifndef TOPCOMMONWORDS_TOPCOMMONWORDS_H
#define TOPCOMMONWORDS_TOPCOMMONWORDS_H

#endif //TOPCOMMONWORDS_TOPCOMMONWORDS_H

#include <map>
#include <unordered_map>
#include <string>
#include <vector>


std::map<int, std::vector<std::string>, bool (*)(const int&, const int&)> findTopCommonWords(const std::string& fileName,
                                                                                             const int& numWords,
                                                                                             const std::vector<std::string>& uninterestingWords);

std::unordered_map<std::string, int> getWordCounts(const std::string& fileName,
                                                   const std::vector<std::string>& uninterestingWords);


std::map<int, std::vector<std::string>> flipMap(const std::unordered_map<std::string, int>& map);
bool larger(const int& a, const int& b);

