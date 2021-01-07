#include <fstream>
#include <algorithm>
#include <iterator>
#include "TopCommonWords.h"
#include "Contains.h"
#include "ExtraStringMethods.h"

/**
 * Find the top N most occurring words in the file
 * @param fileName: the name of the file to search
 * @param numWords: how many words to search for
 * @param uninterestingWords: words to ignore
 * @return
 */
std::map<int,
         std::vector<std::string>,
         bool (*)(const int&, const int&)> findTopCommonWords(const std::string& fileName,
                                                              const int& numWords,
                                                              const std::vector<std::string>& uninterestingWords) {

  auto wordCounts = getWordCounts(fileName, uninterestingWords);
  auto countsToWords = flipMap(wordCounts);
  auto lastWord = countsToWords.crbegin();
  auto numElementsToMove = std::min(numWords, static_cast<int>(countsToWords.size()));
  std::advance(lastWord, numElementsToMove);
  return {countsToWords.crbegin(),
          lastWord,
          larger};
}

/**
 * Flip the map so that values become keys and the keys become values
 * Since there can be multiple values in
 * @param map
 * @return
 */
std::map<int, std::vector<std::string>> flipMap(const std::unordered_map<std::string, int>& map) {
  std::map<int, std::vector<std::string>> flippedMap;

  for (const auto& element : map) {
    if (flippedMap.count(element.second) == 0) { //first time seeing this element
      flippedMap.insert({element.second, {element.first}});
    } else { //seen it before so add it to the vector of values
      flippedMap.at(element.second).push_back(element.first);
    }
  }

  //sort the elements
  for (auto& countsAndWords : flippedMap) {
    auto& words = countsAndWords.second;
    std::sort(words.begin(), words.end());
  }

  return flippedMap;
}

std::unordered_map<std::string, int> getWordCounts(const std::string& fileName,
                                                   const std::vector<std::string>& uninterestingWords) {
  std::ifstream file(fileName);
  const std::string punctuation(",.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`'");
  if (file) {

    std::unordered_map<std::string, int> wordCounts; //counts of the words
    std::string curWord;
    file >> curWord;
    while (file) {
      stripInPlace(curWord, punctuation); //remove punctuation
      tolowerInPlace(curWord); //make the word lowercase
      if (curWord.empty() || contains(uninterestingWords, curWord)) {
        //if the word is empty or uninteresting, ignore it
      } else if (wordCounts.count(curWord) > 0) { //the word is already there
        wordCounts.at(curWord) += 1;
      } else {
        wordCounts.insert({curWord, 1});
      }
      file >> curWord;
    }
    return wordCounts;
  }
  throw std::logic_error("Could not open file.");
}

bool larger(const int& a, const int& b) {
  return a > b;
}

