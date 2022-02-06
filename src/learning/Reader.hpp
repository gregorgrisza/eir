#include <fstream>
#include <nlohmann/json.hpp>
#include "LearnIntentData.hpp"

using json = nlohmann::json;

class Reader {
    public:
        std::vector<LearnIntentData> read(std::string file);
    private:
        void GetEntities(std::map<std::string, std::string>& entitites, std::string input);
};
