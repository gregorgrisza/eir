#ifndef ANALYZER_H
#define ANALYZER_H

#include "LearnIntentData.hpp"

#include <set>

class Analyzer {
    private:
        std::set<std::string> m_intents;
        std::map<std::string, std::map<std::string, int>> m_bows;
        std::map<std::string, int> m_probes;
        std::map<std::string, std::map<std::string, float>> m_globalWordStrengths;

        float localStrength(std::string intent, std::string word);
        void globalStrengths(std::string word);

    public:
        void analyze(std::vector<LearnIntentData> const& data);
};

#endif
