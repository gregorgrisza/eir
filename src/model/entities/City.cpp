#include <string>
#include "City.hpp"

const std::string City::Name() {
    return City::ID;
}

std::string City::ID = "City";

City::City(const std::string & value) : Location(value) {}
