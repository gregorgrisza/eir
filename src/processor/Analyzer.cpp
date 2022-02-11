
#include "Analyzer.hpp"
#include "Preprocessor.hpp"


void Analyzer::analyze(std::vector<IntentDefinition> const& data) {
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

        m_popularity[word.first] = sumOfStrengths / m_intents.size();

        for (auto intent : m_intents) {
            m_globalWordStrengths[word.first][intent] = localStrengths[intent] / sumOfStrengths;
        }
    }
}

void Analyzer::predict(std::set<std::string> const& words, std::string& intent) {
    std::string winnerIntent;

    std::map<std::string, std::map<std::string, float>> intentWordRating;
    std::map<std::string, float> intentRating;
    for (auto word : words) {
        auto importance = 1 - m_popularity[word];
        if ( m_bows.contains(word) ) {
            for (auto intent : m_intents) {
                auto rating = m_globalWordStrengths[word][intent] * importance;
                intentWordRating[intent][word] += rating;

                // TODO: try: consider here using localWordStrength to decrease global importance and rating
                //   but it might have negative influence on important words - test it

                intentRating[intent] += rating;
            }
        }
    }
    // TODO: try: find unique words, which exist only in one intent, so others could be ignored (?)

    intent = getKeyWithMaxValue(intentRating);
}

//TODO: move templated to utilities
std::string Analyzer::getKeyWithMaxValue(std::map<std::string, float> const& valuesMap) {
    if (valuesMap.empty()) {
        return "";
    }

    std::vector<std::pair<std::string, float>> vec;
    std::copy(valuesMap.begin(),
            valuesMap.end(),
            std::back_inserter<std::vector<std::pair<std::string, float>>>(vec));

    std::sort(vec.begin(), vec.end(),
            [](const std::pair<std::string, float> &l, const std::pair<std::string, float> &r)
            {
                if (l.second != r.second) {
                    return l.second > r.second;
                }

                return l.first > r.first;
            });

    return vec[0].first;
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
