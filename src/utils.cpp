#include "utils.h"
#include <filesystem>
#include <format>
#include <fstream>
#include <stdexcept>

namespace utils {

std::string read_puzzle_input(int day) {

  std::string input_file_name = std::format("day{}-input.txt", day);

  std::filesystem::path input_file_path =
      std::filesystem::path("puzzle-inputs") / input_file_name;

  if (!std::filesystem::exists(input_file_path)) {
    throw std::runtime_error("File not found: " + input_file_path.string());
  }

  std::ifstream inputFile(input_file_path);

  std::string content((std::istreambuf_iterator<char>(inputFile)),
                      std::istreambuf_iterator<char>());
  return content;
}

} // namespace utils
