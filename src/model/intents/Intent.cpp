#include "Intent.hpp"
#include "../entities/EntityBuilderProxy.hpp"


Intent::Intent(const std::map<std::string, std::string>& entitiesData) {
    EntitiesConfigurations = entitiesData;
}

void Intent::execute() {
    for (auto entityConfiguration : this->EntitiesConfigurations ) {
        auto entity = EntityBuilderProxy().build(entityConfiguration);
    }
}
