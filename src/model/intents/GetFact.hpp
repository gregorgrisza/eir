#ifndef GETFACT_H
#define GETFACT_H

#include <memory>
#include <string>
#include "Intent.hpp"

class GetFact : public Intent {
    public:
        GetFact(const std::map<std::string, std::string>& entitiesConfigurations);
        const std::string Name() override;
        static std::string ID;
        std::string execute() override;
};

#endif