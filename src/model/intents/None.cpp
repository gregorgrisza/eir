#include <sstream>
#include "None.hpp"

None::None(const std::map<std::string, std::string>& entitiesConfigurations) : Intent(entitiesConfigurations) {}

None::~None() {}

const std::string None::Name() {
    return None::ID;
}

std::string None::execute() {
    std::stringstream stream;
    stream << prefix() << this->Name();

    return stream.str();
}

std::string None::ID = "None";