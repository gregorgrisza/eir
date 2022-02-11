#ifndef INTENTDEFINITION_H
#define INTENTDEFINITION_H


#include <string>
#include <vector>
#include <map>

class IntentDefinition {
    public:
        std::vector<std::string> Input;
        std::map<std::string, std::string> EntitiesConfigurations;
        std::string Intent;
};

#endif
