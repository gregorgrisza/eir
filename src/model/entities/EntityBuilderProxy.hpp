#ifndef ENTITYBUILDERPROXY_H
#define ENTITYBUILDERPROXY_H

#include <tuple>
#include <string>
#include <map>
#include <functional>
#include <memory>
#include <string>

#include "City.hpp"
#include "Date.hpp"
#include "Entity.hpp"

using TypesMap = std::map<std::string, std::function<std::unique_ptr<Entity>(std::string const &)>>;

// TODO: make it singleton
class EntityBuilderProxy {

    const TypesMap Creators = {
        {City::ID, [](std::string const & value) -> std::unique_ptr<Entity> { return std::make_unique<City>(value); } },
        {Date::ID, [](std::string const & value) -> std::unique_ptr<Entity> { return std::make_unique<Date>(value); } },
    };

    public:
        std::unique_ptr<Entity> build(std::pair<std::string, std::string> configuration);
};

#endif