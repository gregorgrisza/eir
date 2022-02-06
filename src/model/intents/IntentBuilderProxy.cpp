#include "IntentBuilderProxy.hpp"

std::unique_ptr<Intent> IntentBuilderProxy::build(std::string intent, std::map<std::string, std::string> entitiesData) {
    if (Creators.contains(intent)) {
        return Creators.at(intent)( entitiesData );
    }
    return Creators.at(None::ID)( {} );;
}
