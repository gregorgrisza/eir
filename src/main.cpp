#include <functional>
#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>

#include "spdlog/spdlog.h"
#include "processor/Preprocessor.hpp"
#include "processor/Reader.hpp"
#include "processor/Analyzer.hpp"


int main(int argc, const char **argv)
{

  std::unique_ptr<Reader> reader = std::make_unique<Reader>();

  const auto file = "data/train_data.json";
  Analyzer analyzer = Analyzer();
  if (std::filesystem::exists(file)) {
    analyzer.analyze(reader->read(file));
  }

  std::string sentence;
  while (std::getline(std::cin, sentence) && !sentence.empty())
  {
    std::cout << "\033[F" << sentence << " => " << analyzer.predict(sentence) << std::endl;
  }

  std:: cout << "Bye Bye!" << std::endl;
  return 0;
}
