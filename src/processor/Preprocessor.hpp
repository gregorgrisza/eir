#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <set>

class Preprocessor {
    public:
        static std::set<std::string> tokenize( std::string sentence );
        static void normalize(std::string& sentence);
        static std::set<std::string> sanitize( std::set<std::string> const& sentence );
};

#endif