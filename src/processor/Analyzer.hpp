#ifndef ANALYZER_H
#define ANALYZER_H

#include "IntentDefinition.hpp"

#include <set>

class Analyzer {
    private:
        std::set<std::string> m_intents;

        // TODO: save mem, merge those two together
        std::map<std::string, std::map<std::string, int>> m_bows;
        std::map<std::string, std::map<std::string, float>> m_globalWordStrengths;

        std::map<std::string, int> m_probes;
        std::map<std::string, float> m_popularity;

        std::string getKeyWithMaxValue(std::map<std::string, float> const& valuesMap);
        float localStrength(std::string intent, std::string word);
        void globalStrengths(std::string word);

    public:
        void analyze(std::vector<IntentDefinition> const& data);

        void predict(std::set<std::string> const&, std::string&);
};

#endif
