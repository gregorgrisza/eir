#include <sstream>
#include <algorithm>
#include "Preprocessor.hpp"


void Preprocessor::normalize(std::string& sentence) {
    std::transform(sentence.begin(), sentence.end(), sentence.begin(),
        [](unsigned char c){ return std::tolower(c); });
}

void Preprocessor::removeStopWords(std::string& sentence) {
    std::replace(sentence.begin(), sentence.end(), ',', ' ');
}

std::set<std::string> Preprocessor::tokenize( std::string sentence ) {
    std::set<std::string> result;
    std::istringstream iss(sentence);
    for (std::string s; iss >> s; )
        result.insert(s);
    return result;
}

void Preprocessor::sanitize(std::string & token) {
        token.erase(
            std::remove_if(
                token.begin(),
                token.end(),
                [](auto ch) {
                    return ::isdigit(ch) || ::ispunct(ch);
                }
        ), token.end());
}

std::set<std::string> Preprocessor::sanitize( std::set<std::string> const& sentence ) {
    std::set<std::string> result;
    for (std::string token : sentence)
    {
        Preprocessor::sanitize(token);
        if (token.length() > 0 ) {
            result.insert(token);
        }
    }
    return result;
}