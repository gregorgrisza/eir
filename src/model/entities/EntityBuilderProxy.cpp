#include "EntityBuilderProxy.hpp"

std::unique_ptr<Entity> EntityBuilderProxy::build(std::tuple<std::string, std::string> configuration) {
    auto result = Creators.at(std::get<0>(configuration))( std::get<1>(configuration) );
    return result;
}
