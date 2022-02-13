#ifndef INTENTRECOGNITIONSERVICE_H
#define INTENTRECOGNITIONSERVICE_H

#include <string>
#include <memory>
#include "../processor/IntentDefinition.hpp"
#include "../processor/Analyzer.hpp"
#include "../processor/Reader.hpp"
#include "EntityRecognizer.hpp"

class IntentRecognitionService {
    public:
        IntentRecognitionService();
        void init(std::string filePath = {});
        IntentDefinition recognize(std::string sentence);
    private:
        std::shared_ptr<Analyzer> m_analyzer;
        std::unique_ptr<Reader> m_reader;
        std::unique_ptr<EntityRecognizer> m_recognizer;
};

#endif