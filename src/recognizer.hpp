#include <set>

class Recognizer {
    public:
        Recognizer();
        std::set<std::string> tokenize( std::string sentence );
        void preprocess(std::string& sentence);
        void normalize(std::string& sentence);
        std::set<std::string> sanitize( std::set<std::string> const& sentence );
};
