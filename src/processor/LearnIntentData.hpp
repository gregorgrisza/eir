#ifndef LEARNINTENTDATA_H
#define LEARNINTENTDATA_H


#include <string>
#include <vector>
#include <map>

class LearnIntentData {
    public:
        std::vector<std::string> Input;
        std::map<std::string, std::string> EntitiesConfigurations;
        std::string Intent;
};

#endif
