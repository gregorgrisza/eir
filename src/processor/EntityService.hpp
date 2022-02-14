#ifndef ENTITYSERVICE_H
#define ENTITYSERVICE_H

/**
 * @brief Entity recognition service
 *
 * @tparam T Entity identifiers types
 */
template<class T>
class EntityService {
    public:
        /**
         * @brief Get the Entities
         *
         * Recognize entities from input tokens.
         *
         * @param token
         * @param entitiesConfigurations
         */
        virtual void getEntities(std::set<std::string> const& token, std::map<std::string, T>& entitiesConfigurations) = 0;
};

#endif