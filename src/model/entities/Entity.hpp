#ifndef ENTITY_H
#define ENTITY_H

#include <any>
#include <string>

class Entity {
    public:
        virtual const std::string Name() = 0;

        Entity(const std::string & value);
        std::string Value;
        virtual void executeAction();
};

#endif
