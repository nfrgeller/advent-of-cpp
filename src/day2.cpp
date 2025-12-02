#include "utils.h"
#include <iostream>
#include <string>
#include <vector>

long long part1() {
  std::string puzzle_input = utils::read_puzzle_input(2);
  std::vector<std::string> id_pairs;

  std::string chunk;
  for (char c : puzzle_input) {
    if (c == ',') {
      id_pairs.push_back(chunk);
      chunk = "";
    } else if (c != '\n') {
      chunk += c;
    }
  }

  if (!chunk.empty()) {
    id_pairs.push_back(chunk);
  }

  long long result = 0;

  for (const std::string &range : id_pairs) {
    std::string start_string;
    std::string end_string;
    bool on_end = false;
    for (char c : range) {
      if (c == '-') {
        on_end = true;
      } else if (on_end) {
        end_string += c;
      } else {
        start_string += c;
      }
    }

    long long start = std::stoll(start_string);
    long long end = std::stoll(end_string);

    for (long long i = start; i <= end; i++) {
      std::string str = std::to_string(i);
      int length = str.size();
      if (length % 2 == 0) {
        std::string beginning = str.substr(0, length / 2);
        std::string ending = str.substr(length / 2);
        if (beginning == ending) {
          result += i;
        }
      }
    }
  }
  return result;
}

int main() { std::cout << part1() << std::endl; }
