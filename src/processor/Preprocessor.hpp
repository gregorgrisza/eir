#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <set>

/**
 * @brief Set of static method of sanitizing User input.
 */
class Preprocessor {
    public:
        /**
         * @brief Split sentence on individual tokens/words
         *
         * @param sentence
         * @return std::set<std::string>
         */
        static std::set<std::string> tokenize( std::string sentence );

        /**
         * @brief Transform sentence without changing meaning of characters.
         *
         * Mostly it's lowercase, which doesn't change information.
         *
         * @param sentence
         */
        static void normalize(std::string& sentence);

        /**
         * @brief Clean up sentence by tokens.
         *
         * Remove punctuations and digits which are not treated as intent recognition
         * related information.
         *
         * @param sentence
         * @return std::set<std::string>
         */
        static std::set<std::string> sanitize( std::set<std::string> const& sentence );

        /**
         * @brief Clean up sentence.
         *
         * Remove punctuations and digits which are not treated as intent recognition
         * related information.
         *
         * @param sentence
         * @return std::set<std::string>
         */
        static void sanitize(std::string & token);

        /**
         * @brief Remove stop words which doesn't have influence on sentence meaning
         * related to intent recognition.
         *
         * @param sentence
         */
        static void removeStopWords(std::string& sentence);
};

#endif