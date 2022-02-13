#include <sstream>
#include <memory>
#include "Intent.hpp"


Intent::Intent(const std::map<std::string, std::string>& entitiesData) {
    EntitiesConfigurations = entitiesData;
}

std::string Intent::prefix() {
    return "Intent: ";
}

std::unique_ptr<std::pair<std::string, std::string>> Intent::getEntityDefinition(std::string entityType) {
    for (auto entityDefinition : EntitiesConfigurations) {
        if (entityType == entityDefinition.second) {
            std::pair<std::string, std::string> res = {entityDefinition.first, entityType};
            return std::make_unique<std::pair<std::string, std::string>>( res );
        }
    }
    return nullptr;
}
