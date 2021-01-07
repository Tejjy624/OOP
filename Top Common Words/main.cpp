#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "ExtraStringMethods.h"
#include "TopCommonWords.h"

int main(int argc, char** argv) {
  int numWordsToFind =
      argc >= 3 ? std::stoi(argv[2]) : 10; //if the number of words to display isn't given default to 10
  std::vector<std::string> uninterestingWords{"a", "an", "and", "in", "is", "it", "the"};

  if (argc >= 2) {
    auto topCommonWords = findTopCommonWords(argv[1], numWordsToFind, uninterestingWords);
    int i = 1;
    for (const auto& wordsAndCounts : topCommonWords) {
      const auto& counts = wordsAndCounts.first;
      const auto& words = wordsAndCounts.second;
      std::cout << i << ".) These words appeared " << counts << " times: " << words << std::endl;
      ++i;
    }
  }else{
    std::cout << "Usage: ./TopCommonWords path_to_file [num_words_to_find]" << std::endl;
  }

  return 0;
}
