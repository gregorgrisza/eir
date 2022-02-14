#ifndef READER_H
#define READER_H


#include <fstream>
#include "IntentDefinition.hpp"

/**
 * @brief Learn data reader.
 */
class Reader {
    public:

        /**
         * @brief Read learn data from JSON
         *
         * @param file Path to file.
         * @return std::vector<IntentDefinition>
         */
        std::vector<IntentDefinition> read(std::string file);
    private:
        void GetEntities(std::map<std::string, std::string>& entitites, std::string& sentence, std::string input);
};

#endif