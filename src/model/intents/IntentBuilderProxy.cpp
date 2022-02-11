#include "IntentBuilderProxy.hpp"

std::unique_ptr<Intent> IntentBuilderProxy::build(std::string const& intent, std::map<std::string, std::string> const& entitiesData) {
    if (Creators.contains(intent)) {
        return Creators.at(intent)( entitiesData );
    }
    return Creators.at(None::ID)( {} );;
}
