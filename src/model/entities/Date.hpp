#ifndef DATE_H
#define DATE_H

#include "Entity.hpp"

class Date : public Entity {
    public:
        static std::string ID;
        std::string const Name() override;
        Date(const std::string & value);
};

#endif