#ifndef INTENTRECOGNITIONSERVICE_H
#define INTENTRECOGNITIONSERVICE_H

#include <string>
#include <memory>
#include "../processor/IntentDefinition.hpp"
#include "../processor/Analyzer.hpp"
#include "../processor/Reader.hpp"
#include "EntityRecognizer.hpp"

/**
 * @brief Core recognition service
 */
class IntentRecognitionService {
    public:
        /**
         * @brief Construct a new Intent Recognition Service object
         *
         */
        IntentRecognitionService();

        /**
         * @brief Initialize learn data.
         *
         * @param filePath
         */
        void init(std::string filePath = {});

        /**
         * @brief Recognize intent
         *
         * @param sentence User input / sentence, e.g. "Tell me the fact."
         * @return IntentDefinition
         */
        IntentDefinition recognize(std::string sentence);
    private:
        std::shared_ptr<Analyzer> m_analyzer;
        std::unique_ptr<Reader> m_reader;
        std::unique_ptr<EntityRecognizer> m_recognizer;
};

#endif