#ifndef READER_H
#define READER_H


#include <fstream>
#include "IntentDefinition.hpp"


class Reader {
    public:
        std::vector<IntentDefinition> read(std::string file);
    private:
        void GetEntities(std::map<std::string, std::string>& entitites, std::string& sentence, std::string input);
};

#endif