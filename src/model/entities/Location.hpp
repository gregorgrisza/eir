#ifndef LOCATION_H
#define LOCATION_H

#include "Entity.hpp"

class Location : public Entity {
    public:
        static std::string ID;
        std::string const Name() override;
        Location(const std::string & value);
};

#endif