#include <sstream>
#include "Intent.hpp"
#include "../entities/EntityBuilderProxy.hpp"


Intent::Intent(const std::map<std::string, std::string>& entitiesData) {
    EntitiesConfigurations = entitiesData;
}

std::string Intent::execute() {
    std::stringstream stream;
    stream << "Intent: (" << this->Name() ;
    for (auto entityConfiguration : this->EntitiesConfigurations ) {
        stream << " " << EntityBuilderProxy().build(entityConfiguration)->Name();
    }
    stream << ")";

    return stream.str();
}
