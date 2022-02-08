#include <functional>
#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>

#include "spdlog/spdlog.h"
#include "learning/Preprocessor.hpp"
#include "learning/Reader.hpp"
#include "learning/Analyzer.hpp"


int main(int argc, const char **argv)
{
  bool nextQuestion = false;

  while (nextQuestion)
  {
    std::string sentence;
    std::cout << "What can I do for you?\n";
    std::getline(std::cin, sentence);
    if ( sentence.compare("q") == 0) {
      nextQuestion = false;
    }

    // std::shared_ptr<Preprocessor> recognizer = std::make_shared<Preprocessor>();
    std::cout << "Is this what you really want? : " << sentence << "\n";
    Preprocessor::normalize(sentence);
    auto tokens = Preprocessor::tokenize(sentence);

    for (auto token : tokens)
    {
      spdlog::info(token);
    }
    spdlog::info("-------");
    for (auto token : Preprocessor::sanitize(tokens))
    {
      spdlog::info(token);
    }
  }


  std::shared_ptr<Reader> reader = std::make_shared<Reader>();
  const auto dir = std::filesystem::current_path();
  const auto file = "data/train_data.json";
  if (std::filesystem::exists(file)) {
    Analyzer().analyze(reader->read(file));
  }

  spdlog::info("Bye Bye!");
}
