#include "EntityBuilderProxy.hpp"

std::unique_ptr<Entity> EntityBuilderProxy::build(std::pair<std::string, std::string> configuration) {
    auto result = Creators.at(configuration.second)( configuration.first );
    return result;
}
