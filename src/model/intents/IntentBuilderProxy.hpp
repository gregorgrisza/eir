#ifndef ENTITYBUILDERPROXY_H
#define ENTITYBUILDERPROXY_H

#include <tuple>
#include <string>
#include <map>
#include <functional>
#include <memory>
#include <string>

#include "Intent.hpp"
#include "GetWeather.hpp"
#include "GetFact.hpp"
#include "None.hpp"

using TypesMap = std::map<std::string, std::function<std::unique_ptr<Intent>(std::map<std::string, std::string> const &)>>;

// TODO: make it singleton
class IntentBuilderProxy {

    const TypesMap Creators = {
        {GetWeather::ID, [](std::map<std::string, std::string> const & value) -> std::unique_ptr<Intent> { return std::make_unique<GetWeather>(value); } },
        {GetFact::ID, [](std::map<std::string, std::string> const & value) -> std::unique_ptr<Intent> { return std::make_unique<GetFact>(value); } },
        {None::ID, [](std::map<std::string, std::string> const & value) -> std::unique_ptr<Intent> { return std::make_unique<GetFact>(value); } },
    };

    public:
        std::unique_ptr<Intent> build(std::string const& intent, std::map<std::string, std::string> const& entitiesData);
};

#endif
