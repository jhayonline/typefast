#pragma once

#include <chrono>
#include <string>

struct Stats {
  int wpm = 0;
  double accuracy = 0.0;
  double timeSeconds = 0.0;
  int correctChars = 0;
  int totalChars = 0;
  int totalWords = 0;
  int totalMistakes = 0;
  std::chrono::steady_clock::time_point startTime;
  std::chrono::steady_clock::time_point endTime;

  void calculate();
  std::string formatTime() const;
  std::string toString() const;
};
