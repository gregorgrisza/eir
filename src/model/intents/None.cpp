#include "None.hpp"

None::None(const std::map<std::string, std::string>& entitiesConfigurations) : Intent(entitiesConfigurations) {}

const std::string None::Name() {
    return None::ID;
}

std::string None::ID = "None";