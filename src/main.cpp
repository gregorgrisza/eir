#include <functional>
#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>

#include "spdlog/spdlog.h"
#include "service/IntentRecognitionService.hpp"

int main(int argc, const char **argv)
{

  auto service = std::make_unique<IntentRecognitionService>();
  service->init();


  std::string sentence;
  while (std::getline(std::cin, sentence) && !sentence.empty())
  {
    std::string output;
    auto intent = service->recognize(sentence);
    std::cout << "\033[F" << sentence << " => " << intent.Intent << std::endl;
  }

  std:: cout << "Bye Bye!" << std::endl;
  return 0;
}
