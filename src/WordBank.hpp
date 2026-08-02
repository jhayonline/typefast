#pragma once

#include <random>
#include <string>
#include <vector>

class WordBank {
public:
  WordBank();

  void loadFromFile(const std::string &filename);
  void loadDefaults();

  std::string generateSentence(int wordCount);

  int size() const { return words.size(); }

private:
  std::vector<std::string> words;
  std::mt19937 rng;
};
