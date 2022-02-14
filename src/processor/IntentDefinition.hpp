#ifndef INTENTDEFINITION_H
#define INTENTDEFINITION_H


#include <string>
#include <vector>
#include <map>

class IntentDefinition {
    public:
        /**
         * @brief User Input data. Vecotr of sanitized sentences.
         */
        std::vector<std::string> Input;

        /**
         * @brief Entities definition recognized in Input sentence
         */
        std::map<std::string, std::string> EntitiesConfigurations;

        /**
         * @brief Intent type definition
         */
        std::string Intent;
};

#endif
