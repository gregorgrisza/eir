#include <fstream>
#include <nlohmann/json.hpp>
#include "IntentDefinition.hpp"

using json = nlohmann::json;

class Reader {
    public:
        std::vector<IntentDefinition> read(std::ifstream &);
    private:
        void GetEntities(std::map<std::string, std::string>& entitites, std::string& sentence, std::string input);
};
