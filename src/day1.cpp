#include "utils.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string puzzle_input = utils::read_puzzle_input(1);
  std::istringstream stream(puzzle_input);
  std::string current_line;

  int location = 50;
  int result = 0;

  while (std::getline(stream, current_line)) {
    char direction = current_line[0];
    int distance = std::stoi(current_line.substr(1));

    if (direction == 'L') {
      distance *= -1;
    }

    location = (location + distance) % 100;

    if (location == 0) {
      result++;
    }
  }

  std::cout << result << std::endl;

  return 0;
}
