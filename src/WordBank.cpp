#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>

#include "WordBank.hpp"

WordBank::WordBank() : rng(std::random_device{}()) {
  loadDefaults();

  // try to load from file if exists
  if (std::filesystem::exists("src/words.txt")) {
    loadFromFile("src/words.txt");
  }
}

void WordBank::loadDefaults() {
  words = {"the",        "be",         "to",        "of",         "and",
           "a",          "in",         "that",      "have",       "i",
           "it",         "for",        "not",       "on",         "with",
           "he",         "as",         "you",       "do",         "at",
           "this",       "but",        "his",       "by",         "from",
           "they",       "we",         "say",       "her",        "she",
           "or",         "an",         "will",      "my",         "one",
           "all",        "would",      "there",     "their",      "what",
           "so",         "up",         "out",       "if",         "about",
           "who",        "get",        "which",     "go",         "me",
           "when",       "make",       "can",       "like",       "time",
           "no",         "just",       "him",       "know",       "take",
           "people",     "into",       "year",      "your",       "good",
           "some",       "could",      "them",      "see",        "other",
           "than",       "then",       "now",       "look",       "only",
           "come",       "its",        "over",      "think",      "also",
           "back",       "after",      "use",       "two",        "how",
           "our",        "work",       "first",     "well",       "way",
           "even",       "new",        "want",      "because",    "any",
           "these",      "give",       "day",       "most",       "us",
           "after",      "again",      "against",   "along",      "already",
           "always",     "among",      "another",   "anything",   "around",
           "attention",  "away",       "become",    "before",     "begin",
           "behind",     "believe",    "benefit",   "better",     "between",
           "beyond",     "brother",    "budget",    "building",   "business",
           "capital",    "career",     "center",    "chance",     "change",
           "choice",     "choose",     "church",    "citizen",    "civil",
           "college",    "commercial", "common",    "company",    "compare",
           "computer",   "concern",    "condition", "conference", "consumer",
           "continue",   "control",    "country",   "county",     "couple",
           "course",     "culture",    "customer",  "daughter",   "decision",
           "defense",    "degree",     "democrat",  "democratic", "describe",
           "design",     "despite",    "determine", "develop",    "development",
           "difference", "different",  "direction", "director"};
}

void WordBank::loadFromFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open())
    return;

  std::string word;
  words.clear();
  while (file >> word) {
    if (!word.empty() && word.length() > 1) {
      words.push_back(word);
    }
  }
  std::cout << "Loaded " << words.size() << " words from file" << std::endl;
}
