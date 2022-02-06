#include "Date.hpp"

const std::string Date::Name() {
    return Date::ID;
}

std::string Date::ID = "Date";

Date::Date(const std::string & value) : Entity(value) {}