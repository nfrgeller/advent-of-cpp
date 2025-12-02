#include "utils.h"
#include <iostream>
#include <sstream>
#include <string>

int part1() {
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

    int total = location + distance;

    location = total % 100;
    if (location == 0) {
      result++;
    }
  }
  return result;
}

int part2() {
  std::string puzzle_input = utils::read_puzzle_input(1);
  std::istringstream stream(puzzle_input);
  std::string current_line;

  int location = 50;
  int result = 0;

  while (std::getline(stream, current_line)) {

    char direction = current_line[0];
    int distance = std::stoi(current_line.substr(1));
    int i = location;
    int count = 0;

    while (count < distance) {
      if (direction == 'L') {
        i = (i - 1 + 100) % 100;
      } else {
        i = (i + 1) % 100;
      }
      if (i == 0) {
        result++;
      }
      location = i;
      count++;
    }
  }
  return result;
}

int main() {
  std::cout << part1() << std::endl;
  std::cout << part2() << std::endl;
}
