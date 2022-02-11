#ifndef INTENTRECOGNITIONSERVICE_H
#define INTENTRECOGNITIONSERVICE_H

#include <string>
#include <memory>
#include "../processor/IntentDefinition.hpp"
#include "../processor/Analyzer.hpp"
#include "../processor/Reader.hpp"

class IntentRecognitionService {
    public:
        IntentRecognitionService();
        void init();
        IntentDefinition recognize(std::string sentence);
    private:
        std::unique_ptr<Analyzer> m_analyzer;
        std::unique_ptr<Reader> m_reader;
        std::unique_ptr<EntityRecognizer> m_recognizer;
};

#endif