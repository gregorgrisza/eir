#ifndef ENTITYRECOGNIZER_H
#define ENTITYRECOGNIZER_H

#include <string>
#include <map>

class EntityRecognizer {
    public:
        void recognize(std::string sentence, std::map<std::string, std::string>& EntitiesConfigurations);
};

#endif