#ifndef ENTITYRECOGNIZER_H
#define ENTITYRECOGNIZER_H

#include <string>
#include <map>
#include <memory>
#include <set>
#include "EntityService.hpp"

/**
 * @brief Simple brigde class controling entities recognizing by EntityService.
 */
class EntityRecognizer {
    public:

        /**
         * @brief Construct a new Entity Recognizer object
         *
         * @param std::shared_ptr<EntityService<std::string>> Entity Service.
         */
        EntityRecognizer(std::shared_ptr<EntityService<std::string>>);

        /**
         * @brief Recognize entities
         *
         * Recognizes all entities from sanitized words.
         *
         * @param std::set<std::string> const& Input words.
         * @param std::map<std::string, std::string>& Output map storing entities configuration.
         */
        void recognize(std::string const&, std::map<std::string, std::string>&);

    private:
        std::shared_ptr<EntityService<std::string>> m_entityService;
};

#endif