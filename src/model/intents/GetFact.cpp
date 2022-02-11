#include "GetFact.hpp"

GetFact::GetFact(const std::map<std::string, std::string>& entitiesConfigurations) : Intent(entitiesConfigurations) {}

const std::string GetFact::Name() {
    return GetFact::ID;
}

std::string GetFact::ID = "Get Fact";