#ifndef INTENT_H
#define INTENT_H

#include <string>
#include <map>
#include <memory>

class Intent {
    public:
        std::map<std::string, std::string> EntitiesConfigurations;

        Intent(const std::map<std::string, std::string>& entitiesConfigurations);

        virtual const std::string Name() = 0;
        virtual std::string execute() = 0;

    protected:
        std::string prefix();
        std::unique_ptr<std::pair<std::string, std::string>> getEntityDefinition(std::string entityType);
};

#endif