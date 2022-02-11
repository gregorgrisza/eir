#include "GetWeather.hpp"

GetWeather::GetWeather(const std::map<std::string, std::string>& entitiesConfigurations) : Intent(entitiesConfigurations) {}

const std::string GetWeather::Name() {
    return GetWeather::ID;
}

std::string GetWeather::ID = "Get Weather";