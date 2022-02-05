#include <sstream>
#include <algorithm>
#include "recognizer.hpp"
#include "spdlog/spdlog.h"

Recognizer::Recognizer() {

}

void Recognizer::preprocess(std::string& sentence) {
    std::replace(sentence.begin(), sentence.end(), ',', ' '); 
}

void Recognizer::normalize(std::string& sentence) {
    std::transform(sentence.begin(), sentence.end(), sentence.begin(),
        [](unsigned char c){ return std::tolower(c); });
}

std::set<std::string> Recognizer::tokenize( std::string sentence ) {
    std::set<std::string> result;
    std::istringstream iss(sentence);
    for (std::string s; iss >> s; )
        result.insert(s);
    return result;
}

std::set<std::string> Recognizer::sanitize( std::set<std::string> const& sentence ) {
    std::set<std::string> result;
    for (std::string token : sentence)
    {
        token.erase(
            std::remove_if(
                token.begin(),
                token.end(),
                [](auto ch) {
                    return ::isdigit(ch) || ::ispunct(ch);
                }
        ), token.end());

        if (token.length() > 0 ) {
            result.insert(token);
        }
    }
    return result;
}