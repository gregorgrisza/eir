#include <functional>
#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>

#include "spdlog/spdlog.h"
#include "service/IntentRecognitionService.hpp"
#include "model/intents/IntentBuilderProxy.hpp"

int main(int argc, const char **argv)
{

  // Create recognition service
  auto service = std::make_unique<IntentRecognitionService>();

  // Initialize learn data
  service->init();


  // Talk to User, wait in loop for User input confirmed by Enter
  //  empty line finishes program.
  std::string sentence;
  while (std::getline(std::cin, sentence) && !sentence.empty())
  {
    std::string output;

    // Recognize User input
    auto intentDefinition = service->recognize(sentence);

    // create real object using recognized intent configuration
    auto intent = IntentBuilderProxy().build(intentDefinition.Intent, intentDefinition.EntitiesConfigurations);

    // Execute intent task and print out the result.
    std::cout << "\033[F" << sentence << " => Prints (" << intent->execute() << ")" << std::endl;
  }

  std:: cout << "Bye Bye!" << std::endl;
  return 0;
}
