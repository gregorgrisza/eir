#include <functional>
#include <iostream>
#include "spdlog/spdlog.h"
#include "recognizer.hpp"

int main(int argc, const char **argv)
{
  bool nextQuestion = true;

  while (nextQuestion)
  {
    std::string sentence;
    std::cout << "What can I do for you?\n";
    std::getline(std::cin, sentence);
    if ( sentence.compare("q") == 0) {
      nextQuestion = false;
    }

    std::shared_ptr<Recognizer> recognizer = std::make_shared<Recognizer>();
    std::cout << "Is this what you really want? : " << sentence << "\n";
    recognizer->preprocess(sentence);
    recognizer->normalize(sentence);
    auto tokens = recognizer->tokenize(sentence);

    for (auto token : tokens)
    {
      spdlog::info(token);
    }
    spdlog::info("-------");
    for (auto token : recognizer->sanitize(tokens))
    {
      spdlog::info(token);
    }
  }

  spdlog::info("Bye Bye!");
}
