#ifndef CITY_H
#define CITY_H

#include "Location.hpp"

class City : public Location {
    public:
        City(const std::string & value);
        static std::string ID;
        std::string const Name() override;
};

#endif
