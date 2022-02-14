#ifndef INTENT_H
#define INTENT_H

#include <string>
#include <map>
#include <memory>
#include "../entities/Entity.hpp"

class Intent {
    public:
        std::map<std::string, std::string> EntitiesConfigurations;

        /**
         * @brief Construct a new Intent object
         *
         * @param entitiesConfigurations Definition required for creation entities
         */
        Intent(const std::map<std::string, std::string>& entitiesConfigurations);

        /**
         * Name identifying Intent.
         */
        virtual const std::string Name() = 0;

        /**
         * @brief Method executing main task of the Intent.
         *
         * @return Task execution textual output
         */
        virtual std::string execute() = 0;

        virtual ~Intent() = 0;

    protected:
        std::string prefix();
        std::unique_ptr<std::pair<std::string, std::string>> getEntityDefinition(std::string entityType);
};

#endif