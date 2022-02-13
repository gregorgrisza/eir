#include <filesystem>
#include "IntentRecognitionService.hpp"
#include "../processor/EntityRecognizer.hpp"
#include "../processor/Preprocessor.hpp"

IntentRecognitionService::IntentRecognitionService()
    :  m_analyzer(std::make_shared<Analyzer>())
     , m_reader(std::make_unique<Reader>())
     , m_recognizer(
          std::make_unique<EntityRecognizer>(
            m_analyzer
          )
        ) {}

void IntentRecognitionService::init(std::string filePath) {
  const auto file = filePath.empty() ? "data/train_data.json" : filePath;
  if (std::filesystem::exists(file)) {
    m_analyzer->analyze(m_reader->read(file));
  }
}

IntentDefinition IntentRecognitionService::recognize(std::string sentence) {
    IntentDefinition intentDefinition;
    Preprocessor::removeStopWords(sentence);

    m_recognizer->recognize(sentence, intentDefinition.EntitiesConfigurations);

    Preprocessor::normalize(sentence);
    intentDefinition.Input.push_back(sentence);

    auto const words = Preprocessor::sanitize(Preprocessor::tokenize(sentence));

    m_analyzer->predict(words, intentDefinition.Intent);

    return intentDefinition;
}
