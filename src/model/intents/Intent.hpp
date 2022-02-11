#ifndef INTENT_H
#define INTENT_H

#include <string>
#include <map>

class Intent {
    public:
        virtual const std::string Name() = 0;
        std::map<std::string, std::string> EntitiesConfigurations;

        Intent(const std::map<std::string, std::string>& entitiesConfigurations);

        std::string execute();
};

#endif