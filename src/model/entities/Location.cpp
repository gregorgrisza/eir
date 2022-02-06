#include "Location.hpp"

const std::string Location::Name() {
    return Location::ID;
}

std::string Location::ID = "Location";

Location::Location(const std::string & value) : Entity(value) {}
