#ifndef ENTITYRECOGNIZER_H
#define ENTITYRECOGNIZER_H

#include <string>
#include <map>
#include <memory>
#include <set>
#include "EntityService.hpp"


class EntityRecognizer {
    public:
        EntityRecognizer(std::shared_ptr<EntityService<std::string>>);
        void recognize(std::string const&, std::map<std::string, std::string>&);

    private:
        std::shared_ptr<EntityService<std::string>> m_entityService;
};

#endif