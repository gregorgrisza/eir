#ifndef INTENTBUILDERPROXY_H
#define INTENTBUILDERPROXY_H

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

/**
 * @brief Builder for all known Intents.
 *
 * Requires Intent::ID parameter defined in each Intent class.
 * Intent::ID must be defined in train data definition.
 */
class IntentBuilderProxy {

    const TypesMap Creators = {
        {GetWeather::ID, [](std::map<std::string, std::string> const & value) -> std::unique_ptr<GetWeather> { return std::make_unique<GetWeather>(value); } },
        {GetFact::ID, [](std::map<std::string, std::string> const & value) -> std::unique_ptr<GetFact> { return std::make_unique<GetFact>(value); } },
        {None::ID, [](std::map<std::string, std::string> const & value) -> std::unique_ptr<None> { return std::make_unique<None>(value); } },
    };

    public:

        /**
         * @brief Build main method for Intents creation.
         *
         * @param intent Unique Intent identifier
         * @param entitiesData Entities data configuration.
         * @return std::unique_ptr<Intent>
         */
        std::unique_ptr<Intent> build(std::string const& intent, std::map<std::string, std::string> const& entitiesData);

};

#endif
