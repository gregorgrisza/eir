#ifndef ENTITY_H
#define ENTITY_H

#include <any>
#include <string>


/**
 * @brief Entity object defines recognized part of sentence.
 * It's an optional parameter for Intent consumed during Intent execution.
 *
 * e.g. "Paris" recognized in sentence: "What is the weather in Paris?"
 *
 * Entity influences intent, so answer can be customized, like in above example
 * system can give more detailed answer about weather having defined location.
 */
class Entity {
    public:

        /**
         * @brief Entity identifier
         *
         * @return const std::string
         */
        virtual const std::string Name() = 0;

        /**
         * @brief Construct a new Entity object
         *
         * @param value Entity value recognized in the sentence.
         */
        Entity(const std::string & value);
        std::string Value;
};

#endif
