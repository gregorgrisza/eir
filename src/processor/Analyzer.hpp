#ifndef ANALYZER_H
#define ANALYZER_H

#include <set>
#include "IntentDefinition.hpp"
#include "EntityService.hpp"

class Analyzer : public EntityService<std::string> {
    private:
        std::set<std::string> m_intents;

        /**
         * @brief Bag of words with counts of words for each intent.
         */
        std::map<std::string, std::map<std::string, int>> m_bows;

        /**
         * @brief Global word strength for intent.
         *
         * Defines how often word appears in all probes comparing to current intent.
         * Helps identifying importance of this word which is important
         * in rating.
         */
        std::map<std::string, std::map<std::string, float>> m_globalWordStrengths;

        /**
         * @brief Count of probes for intent.
         *
         * Each probe stands for learned sentence in train data.
         */
        std::map<std::string, int> m_probes;

        /**
         * @brief Word popularity.
         * Defines how often word appears in all probes.
         */
        std::map<std::string, float> m_popularity;

        /**
         * @brief Entities' database.
         *
         * Stores all unqiue entities by intent.
         * Definition is used to recognize entities in User input sentence.
         */
        std::map<std::string, std::string> m_entitiesDb;

        std::string getKeyWithMaxValue(std::map<std::string, float> const& valuesMap);

        /**
         * @brief Local word strength in the intent.
         *
         * Defines how often word appears in learn data for intent.
         *
         * Calculation: count / probes, where probes - count of learned sentences
         *
         * @param intent
         * @param word
         * @return float Strength of word in intent
         */
        float localStrength(std::string intent, std::string word);

    public:

        /**
         * @brief Analyzing learn data read from JSON definition.
         *
         * Calculates all data required to words ranking across intents.
         *
         * @param data Read from JSON data vector.
         */
        void analyze(std::vector<IntentDefinition> const& data);

        /**
         * @brief Intent prediction by set of words retrieved from User input.
         *
         * Words need to be pre-process, so called must be 'clean'.
         *
         * @param std::set<std::string> const&
         */
        void predict(std::set<std::string> const&, std::string&);

        /**
         * @brief Get the Entities object.
         *
         * Recognizes all entities from sanitized words.
         *
         * @param std::set<std::string> const& Input words.
         * @param std::map<std::string, std::string>& Output map storing entities configuration.
         */
        void getEntities(std::set<std::string> const&, std::map<std::string, std::string>& ) override;
};

#endif
