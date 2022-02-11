#include <filesystem>
#include <memory>
#include "IntentRecognitionService.hpp"
#include "../processor/EntityRecognizer.hpp"
#include "../processor/Preprocessor.hpp"

IntentRecognitionService::IntentRecognitionService()
    :  m_analyzer(std::make_unique<Analyzer>())
     , m_reader(std::make_unique<Reader>())
     , m_recognizer(std::make_unique<EntityRecognizer>()) {
}

void IntentRecognitionService::init() {
  const auto file = "data/train_data.json";
  m_analyzer = std::make_unique<Analyzer>();
  if (std::filesystem::exists(file)) {
    m_analyzer->analyze(m_reader->read(file));
  }
}

IntentDefinition IntentRecognitionService::recognize(std::string sentence) {
    IntentDefinition intentDefinition;

    Preprocessor::normalize(sentence);
    intentDefinition.Input.push_back(sentence);

    m_recognizer->recognize(sentence, intentDefinition.EntitiesConfigurations);

    auto const words = Preprocessor::sanitize(Preprocessor::tokenize(sentence));
    m_analyzer->predict(words, intentDefinition.Intent);

    return intentDefinition;
}
