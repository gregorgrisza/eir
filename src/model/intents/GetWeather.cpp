#include <sstream>
#include "GetWeather.hpp"
#include "../entities/City.hpp"


GetWeather::GetWeather(const std::map<std::string, std::string>& entitiesConfigurations) : Intent(entitiesConfigurations) {}

GetWeather::~GetWeather() {}

const std::string GetWeather::Name() {
    return GetWeather::ID;
}

std::string GetWeather::ID = "Get Weather";

std::string GetWeather::execute() {
    std::stringstream stream;
    std::unique_ptr<std::pair<std::string, std::string>> entityDefinition = getEntityDefinition(City::ID);
    std::string cityInfo;
    if (entityDefinition != nullptr) {
        auto city = City(entityDefinition->first);
        cityInfo += " " + city.Name();
    }
    stream << prefix() << this->Name() << cityInfo;
    return stream.str();
}