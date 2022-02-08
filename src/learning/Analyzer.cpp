
#include "Analyzer.hpp"
#include "Preprocessor.hpp"


void Analyzer::analyze(std::vector<LearnIntentData> const& data) {
    for (auto item : data) {
        for (auto sentence : item.Input) {
            m_probes[item.Intent]++;
            m_intents.insert(item.Intent);
            Preprocessor::normalize(sentence);
            auto words = Preprocessor::sanitize(Preprocessor::tokenize(sentence));
            for (auto word : words) {
                auto in = ++m_bows[word][item.Intent];
            }
        }
    }

    for (auto word : m_bows) {
        float sumOfStrengths = 0;
        std::map<std::string, float> localStrengths = {};
        for (auto intent : m_intents) {
            float strength = localStrength(intent, word.first);
            localStrengths[intent] = strength;
            sumOfStrengths += strength;
        }

        for (auto intent : m_intents) {
            m_globalWordStrengths[intent][word.first] = localStrengths[intent] / sumOfStrengths;
        }
    }
}

float Analyzer::localStrength(std::string intent, std::string word) {
    auto countOfWord = m_bows[word][intent];
    auto countOfProbes = m_probes[intent];
    return float(countOfWord) / float(countOfProbes);
}

void Analyzer::globalStrengths(std::string word){
    float sumOfLocalStrengths;
    for (auto intent : m_intents) {

    }
}
