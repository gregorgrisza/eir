#include "EntityRecognizer.hpp"
#include "Preprocessor.hpp"

EntityRecognizer::EntityRecognizer(std::shared_ptr<EntityService<std::string>> entityService)
    : m_entityService(entityService) {}

void EntityRecognizer::recognize(std::string const& sentence, std::map<std::string, std::string>& entitiesConfigurations) {
    auto mySentence = sentence;

    m_entityService->getEntities(Preprocessor::sanitize(Preprocessor::tokenize(mySentence)), entitiesConfigurations);
}
