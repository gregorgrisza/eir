#ifndef INTENTSMANAGER_H
#define INTENTSMANAGER_H

#include <string>
#include <map>
#include "Intent.hpp"

class IntentsManager {
    public:
        std::map<std::string, Intent> Intents;
};

#endif