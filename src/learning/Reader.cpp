#include <iostream>
#include <regex>
#include <nlohmann/json.hpp>
#include "Reader.hpp"

using json = nlohmann::json;

std::vector<LearnIntentData> Reader::read(std::string file) {
    std::ifstream data_stream(file);
    json json_data;
    data_stream >> json_data;
    std::vector<LearnIntentData> learnIntentDatas;
    for( const auto & item : json_data) {
        // std::cout << std::setw(4) << item << std::endl;
        LearnIntentData learnIntentData;
        learnIntentData.Intent = item["intent"];
        for( const auto &input : item["input"]) {
            std::string sentence;
            GetEntities(learnIntentData.EntitiesConfigurations, sentence, input.get<std::string>());
            learnIntentData.Input.push_back(sentence);
        }
        learnIntentDatas.push_back(learnIntentData);
    }

    return learnIntentDatas;
}

void Reader::GetEntities(std::map<std::string, std::string>& entitiesBuilders, std::string& sentence, std::string input) {
    const std::regex expression("\\[([A-Za-z']+)\\]\\(([A-Za-z]*)\\)");
    std::smatch matches;

    if(std::regex_search(input, matches, expression)) {
        const std::string full = matches[0].str();
        const std::string first = matches[1].str();
        const std::string second = matches[2].str();

        entitiesBuilders.insert( std::make_pair(second, first) );

        input.replace(input.find(full), full.length(), first);
        GetEntities(entitiesBuilders, sentence, input);
    } else {
        sentence = input;
    }
}
